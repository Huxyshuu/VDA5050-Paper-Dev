#!/usr/bin/env python3
"""Validate one or more JSON messages against an official VDA 5050 schema."""

import argparse
import json
from pathlib import Path

import jsonschema


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("--schema", required=True, type=Path)
    parser.add_argument("messages", nargs="+", type=Path)
    args = parser.parse_args()
    schema = json.loads(args.schema.read_text(encoding="utf-8"))
    failed = 0
    for message_path in args.messages:
        try:
            payload = json.loads(message_path.read_text(encoding="utf-8"))
            jsonschema.validate(payload, schema)
            print(f"PASS {message_path}")
        except Exception as exc:
            failed += 1
            print(f"FAIL {message_path}: {exc}")
    return 1 if failed else 0


if __name__ == "__main__":
    raise SystemExit(main())
