import subprocess
import os

kb = 'keychron/c1'
subprocess.run(f"bin/qmk compile -kb {kb} -km default -j{os.cpu_count()}", shell=True)