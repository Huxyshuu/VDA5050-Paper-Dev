#!/usr/bin/env python3
from pathlib import Path
import shutil

root = Path(__file__).resolve().parents[1]
source = root / "schemas" / "vda5050_v3"
target = root / "ros2_ws" / "src" / "vda5050_schemas_v3" / "schemas"
target.mkdir(parents=True, exist_ok=True)
for path in source.glob("*.schema"):
    shutil.copy2(path, target / path.name)
    print(f"synced {path.name}")
