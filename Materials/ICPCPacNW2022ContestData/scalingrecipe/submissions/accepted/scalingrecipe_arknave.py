#!/usr/bin/env python3
n, x, y = map(int, input().split())
for _ in range(n):
    print(int(input()) * y // x)
