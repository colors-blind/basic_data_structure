#!/usr/bin/env python
# coding=utf-8

#    1
#  2   3
#4  5  9 10 
#          11
#
# 1 2 3 4 5 9 10 11
#

# from https://www.hackerrank.com/challenges/tree-level-order-traversal/problem

class Node(object):

    def __init__(self, left, right, data):

        self.left = left
        self.right = right
        self.data = data

    def __repr__(self):
        return str(self.data)


def init_m():

    node11 = Node(None, None, 11)
    node9 = Node(None, None, 9)
    node4 = Node(None, None, 4)
    node5 = Node(None, None, 5)

    node10 = Node(None, node11, 10)
    node2 = Node(node4, node5, 2)
    node3 = Node(node9, node10, 3)
    node1 = Node(node2, node3, 1)
    return node1


# get leaf of a node in left -> right order
# Note: not a smart way to sovle the problem
def get_leaf_of_node(n):

    adict = {n: []}
    if not (n.left or n.right):
        return adict
    if n.left:
        adict[n].append(n.left)
    if n.right:
        adict[n].append(n.right)
    return adict


def get_all_node(adict):
    aset = set()
    for value in adict.values():
        if value:
            for ele in value:
                aset.add(ele)
    return aset


def if_end(adict, root_node):

    keys = set(adict.keys())
    all_node = get_all_node(adict)
    all_node.add(root_node)
    return keys == all_node


def get_adict(root):

    root_node = root
    init_dict = get_leaf_of_node(root)
    while not if_end(init_dict, root_node):
        for value in init_dict.values():
            for ele in value:
                if ele not in init_dict.keys():
                    init_dict[ele] = get_leaf_of_node(ele)[ele]

    alist = [root_node]
    alist += init_dict[root_node]
    all_node = get_all_node(init_dict)
    index = 1
    while len(alist) != len(all_node) + 1:
        alist += init_dict[alist[index]]
        index += 1
    
    return ' '.join(map(lambda a: a.data, alist))


if __name__ == '__main__':
    # a = {1: [2, 3] , 2: [4, 5], 3: [6, 7] , 4: [], 5: [], 6:[], 7:[]}
    # print if_end(a, 1)
    # a = {4: [], 5: [], 10: [11], 2: [4, 5], 3: [9, 10], 1: [2, 3], 11: [], 9: []}
    root = init_m()
    print get_adict(root)



