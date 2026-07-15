# ROX-Diff factsheet

`rox_diff_factsheet.template.json` is schema-valid but is not enabled by default.
Copy it to a robot-specific file, verify every physical/capability value against the
delivered ROX-Diff, and set `factsheet_file` in the adapter YAML to the absolute path.
Do not publish unverified dimensions, load limits, speeds, accelerations, or action
capabilities as production factsheet data.
