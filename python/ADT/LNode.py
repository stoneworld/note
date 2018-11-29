# -*- coding: UTF-8 -*-


class LNode:

    def __init__(self, elem, next_=None):
        self.elem = elem
        self.next = next_


class LinkedListUnderflow(ValueError):
    pass


class LList:
    def __init__(self):
        self._head = None

    # 判断是否是空表
    def is_empty(self):
        return self._head is None

    # 表头插入新数据
    def prepend(self, elem):
        self._head = LNode(elem, self._head)

    # 删除表头节点并返回这个节点的数据
    def pop(self):
        if self._head is None:
            raise LinkedListUnderflow
        e = self._head.elem
        self._head = self._head.next
        return e

    # 链表尾部插入新数据
    def append(self, elem):
        if self._head is None:
            self._head = LNode(elem)
            return
        p = self._head
        while p.next is not None:
            p = p.next
        p.next = LNode(elem)

    # 链表删除尾部节点 返回所删除节点元素值
    def pop_last(self):
        if self._head is None:
            raise LinkedListUnderflow
        p = self._head
        if p.next is None:
            self._head = None
            return p.elem
        while p.next.next is not None:
            p = p.next
        e = p.next.elem
        p.next = None
        return e

    def find(self, pred):
        p = self._head
        while p is not None:
            if pred(p.elem):
                return p.elem
            p = p.next

    def printall(self):
        p = self._head
        while p is not None:
            print(p.elem, end=',')
            if p.next is None:
                print(', ', end='')
            p = p.next
        print('')


# 表对象增加一个表尾节点引用域 o(1)时间找到末节点 提高末端插入效率
class LList1(LList):
    def __init__(self):
        LList.__init__(self)
        self._rear = None

    # 表头插入新数据
    def prepend(self, elem):
        if self._head is None:
            self._head = LNode(elem, self._head)
            self._rear = None
        else:
            self._head = LNode(elem, self._head)

    # 链表尾部插入新数据
    def append(self, elem):
        if self._head is None:
            self._head = LNode(elem, self._head)
            self._rear = self._head
        else:
            self._rear.next = LNode(elem)
            self._rear = self._rear.next

    # 链表删除尾部节点 返回所删除节点元素值
    def pop_last(self):
        if self._head is None:
            raise LinkedListUnderflow
        p = self._head
        if p.next is None:
            self._head = None
            return p.elem
        while p.next.next is not None:
            p = p.next
        e = p.next.elem
        p.next = None
        self._rear = p
        return e


# 循环单链表
class LCList:
    def __init__(self):
        self._rear = None

    def is_empty(self):
        return self._rear is None

    # 表头插入
    def prepend(self, elm):
        p = LNode(elm)
        if self._rear is None:
            p.next = p
            self._rear = p
        else:
            p.next = self._rear.next
            self._rear.next = p

    # 表尾插入
    def append(self, elm):
        p = LNode(elm)
        if self._rear is None:
            p.next = p
            self._rear = p
        else:
            self._rear = LNode(elm, self._rear.next)

    # 前端弹出
    def pop(self):
        if self._rear is None:
            raise LinkedListUnderflow
        p = self._rear.next
        if p.next is p:
            self._rear = None
        else:
            self._rear.next = p.next
        return p.elem


# 双链表开始

# 双链表节点 和 单链表不同的是多了个反向引用域,可在LNode的基础上派生
class DLNode(LNode):
    def __init__(self, elem, prev=None, next_=None):
        LNode.__init__(self, elem, next_)
        self.prev = prev




def test():
    """
    用于测试的主函数
    """
    mlist1 = LList()
    for i in range(10):
        mlist1.prepend(i)
    for i in range(11, 20):
        mlist1.append(i)
    mlist1.printall()
    elem = mlist1.pop_last()
    assert elem == 19


if __name__ == '__main__':
    test()
