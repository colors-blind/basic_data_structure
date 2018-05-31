def levelOrder(root):
    if not root:
        return
    list_queue = [root,]
    # while queue is not empty
    while len(list_queue):
        print list_queue[0].data,
        # pop out the first one
        temp = list_queue.pop(0)
        # add leaf into queue
        if temp.left:
            list_queue.append(temp.left)
        if temp.right:
            list_queue.append(temp.right)

