# -*- coding: UTF-8 -*-


class QueueUnderflow(ValueError):
    pass


# 循环顺序表实现队列,头部删除和查看O(1),尾部加入O(1)
class SQueue(object):
    def __init__(self, init_num=8):
        self._len = init_num    # 存储区长度
        self._elems = [0] * init_num
        self._head = 0          # 表头元素下标
        self._num = 0           # 元素个数

    def is_empty(self):
        return self._num == 0

    def peek(self):
        if self.is_empty():
            raise QueueUnderflow
        return self._elems[self._head]

    def dequeue(self):
        if self.is_empty():
            raise QueueUnderflow
        result = self._elems[self._head]
        self._head = (self._head + 1) % self._len
        self._num -= 1
        return result

    def enqueue(self, elem):
        if self._num == self._len:
            self.__extand()
        self._elems[(self._head + self._num) % self._len] = elem
        self._num += 1

    def __extand(self):
        old_len = self._len
        self._len *= 2
        new_elems = [0] * self._len
        for i in range(old_len):
            new_elems[i] = self._elems[(self._head + i) % old_len]
        self._elems, self._head = new_elems, 0


if __name__ == "__main__":
    q = SQueue()
    for i in range(8):
        q.enqueue(i)
    # for i in range(8):
    #    print(q.dequeue())
    # print(q._num)
    q.enqueue(3)
    print(q._num)
