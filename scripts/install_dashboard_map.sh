#!/usr/bin/env bash
# Copy a ROS map YAML and its referenced image into configs/maps for the Flask UI.
set -euo pipefail

if [[ $# -ne 1 ]]; then
  echo "Usage: $0 /path/to/df_map.yaml" >&2
  exit 2
fi

SOURCE_YAML="$(readlink -f "$1")"
[[ -f "$SOURCE_YAML" ]] || { echo "ERROR: map YAML not found: $SOURCE_YAML" >&2; exit 2; }

PROJECT_ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
DEST_DIR="$PROJECT_ROOT/configs/maps"
mkdir -p "$DEST_DIR"

IMAGE_VALUE="$(awk '
  /^[[:space:]]*image[[:space:]]*:/ {
    sub(/^[[:space:]]*image[[:space:]]*:[[:space:]]*/, "");
    gsub(/^['\"']|['\"']$/, ""); print; exit
  }
' "$SOURCE_YAML")"
[[ -n "$IMAGE_VALUE" ]] || { echo "ERROR: map YAML has no image field" >&2; exit 2; }

if [[ "$IMAGE_VALUE" = /* ]]; then
  SOURCE_IMAGE="$IMAGE_VALUE"
else
  SOURCE_IMAGE="$(dirname "$SOURCE_YAML")/$IMAGE_VALUE"
fi
SOURCE_IMAGE="$(readlink -f "$SOURCE_IMAGE")"
[[ -f "$SOURCE_IMAGE" ]] || { echo "ERROR: map image not found: $SOURCE_IMAGE" >&2; exit 2; }

YAML_NAME="$(basename "$SOURCE_YAML")"
IMAGE_NAME="$(basename "$SOURCE_IMAGE")"
cp "$SOURCE_IMAGE" "$DEST_DIR/$IMAGE_NAME"
cp "$SOURCE_YAML" "$DEST_DIR/$YAML_NAME"

python3 - "$DEST_DIR/$YAML_NAME" "$IMAGE_NAME" <<'PY'
from pathlib import Path
import re, sys
path = Path(sys.argv[1])
image_name = sys.argv[2]
text = path.read_text(encoding="utf-8")
updated, count = re.subn(
    r"(?m)^(\s*image\s*:\s*).*$",
    lambda match: match.group(1) + image_name,
    text,
    count=1,
)
if count != 1:
    raise SystemExit("ERROR: could not rewrite map image field")
path.write_text(updated, encoding="utf-8")
PY

echo "Installed dashboard map:"
echo "  $DEST_DIR/$YAML_NAME"
echo "  $DEST_DIR/$IMAGE_NAME"
echo
echo "Set in configs/fleet_control.env if the filename is not df_map.yaml:"
echo "  FLEET_UI_MAP_YAML=configs/maps/$YAML_NAME"
