#!/usr/bin/python
import sys
def ack (m, n) :
    if m == 0 :
        return n + 1
    if m > 0 and n == 0 :
        return ack(m - 1, 1)
    if m > 0 and n > 0 :
        return ack (m - 1, ack(m, n - 1))
print ack (int(sys.argv[1]), int(sys.argv[2]))
