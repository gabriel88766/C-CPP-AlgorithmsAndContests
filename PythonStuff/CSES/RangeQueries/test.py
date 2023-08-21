#!/bin/python2

import os
import sys
from atexit import register
from io import BytesIO

sys.stdout = BytesIO()
register(lambda: os.write(1, sys.stdout.getvalue()))

input = BytesIO(os.read(0, os.fstat(0).st_size)).readline

class SegmentTree():

    def __init__(self, array):
        # first pad array to nearest 2^k
        # https://stackoverflow.com/questions/466204/rounding-up-to-next-power-of-2
        n = len(array) - 1

        n |= n >> 1
        n |= n >> 2
        n |= n >> 4
        n |= n >> 8
        n |= n >> 16

        n += 1

        self.arr_len = n

        tree = [0] * (n-1) + array + [0] * (n - len(array))
        # build binary tree
        for i in range(n-2, -1, -1):
            tree[i] = sum(tree[i*2 + 1: i*2 + 3])

        self.tree = tree

    def get_sum(self, l, r):
        # get leaf with value 'l'
        l += self.arr_len - 1
        # get leaf with value 'r'
        r += self.arr_len - 2

        sum = 0

        while (l <= r):

            if ((l % 2) == 0):
                # it means l is a right child
                sum += self.tree[l]

                # move l to right by 1, so it becomes a left child and find its parent
                l = (l + 1 - 1) // 2
            else:
                # when l is a left child, when just find its parent
                l = (l - 1) // 2

            if ((r % 2) == 1):
                # it means r is a left chid
                sum += self.tree[r]

                # move r to left by 1, so it becomes a right child and find its parent
                r = (r - 1 - 2) // 2
            else:
                # when r is a right child
                r = (r - 2) // 2

        return sum

    def update(self, i, value):

        node = self.arr_len - 1 + i

        self.tree[node] = value

        while node > 0:
            # find parent node
            node = (node - 1) // 2

            left_child = node * 2 + 1
            right_child = node * 2 + 2

            self.tree[node] = self.tree[left_child] + self.tree[right_child]


if __name__ == "__main__":

    n, q = [int(x) for x in input().split()]
    array = [int(x) for x in input().split()]

    seg = SegmentTree(array)


    for i in range(q):
        t, l, r = [int(x) for x in input().split()]
        if(t == 1):
            seg.update(l, r)
        else:
            print(seg.get_sum(l,r))
