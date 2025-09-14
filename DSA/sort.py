#!/usr/bin/env python3
import random
from pathlib import Path

out = Path(r"D:\Code wala scene\DSA\sort.txt")
out.parent.mkdir(parents=True, exist_ok=True)

nums = list(range(1, 100001))
random.shuffle(nums)

out.write_text("\n".join(map(str, nums)) + "\n", encoding="utf-8")