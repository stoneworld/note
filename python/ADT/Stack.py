# -*- coding: UTF-8 -*-


class StackUnderflow(ValueError): # 栈下溢(空栈访问)
    pass


class SStack:
    def __init__(self):
        self._elems = []

    def is_empty(self):
        return self._elems == []

    def push(self, elem):
        self._elems.append(elem)

    def pop(self):
        if self._elems == []:
            raise StackUnderflow("in SStack.pop()")
        return self._elems.pop()

    def top(self):
        if self._elems == []:
            raise StackUnderflow("in SStack.top()")
        return self._elems[-1]


# 简单应用
# 1. 括号匹配问题
# 给定一个字符串，其中的字符只包含三种括号：花括号{ }、中括号[ ]、圆括号( )，即它仅由 “( ) [ ] { }” 这六个字符组成。
# 设计算法，判断该字符串是否有效，即字符串中括号是否匹配。
# 括号匹配要求括号必须以正确的顺序配对，如 “{ [ ] ( ) }” 或 “[ ( { } [ ] ) ]” 等为正确的格式，而 “[ ( ] )” 或 “{ [ ( ) }” 或 “( { } ] )” 均为不正确的格式。


'''
从前向后扫描字符串，遇到无关字符则跳过；
遇到左括号 x，就把 x 压栈；
遇到右括号 y:
    如果发现栈顶元素x和该括号y匹配，则栈顶元素出栈，继续判断下一个字符；
    如果栈顶元素x和该括号y不匹配，字符串不匹配；
    如果栈为空，字符串不匹配；
扫描完成后，如果栈恰好为空，则字符串匹配，否则，字符串不匹配。
'''


def check_parens(text):
    stack = SStack()
    left_parens = "([{"
    right_parens = ")]}"
    parens = {")":"(", "]":"[", "}":"{"}
    for i in text:
        if i in left_parens:
            stack.push(i)
        elif i in right_parens:
            if stack.is_empty():
                return False
            if parens[i] != stack.pop():
                return False
    if stack.is_empty():
        return True
    return False


# 简单背包问题
def knap_rec(weight, wlist, n):
    if weight == 0:
        return True
    if weight < 0 or (weight > 0 and n < 1):
        return False
    if knap_rec(weight - wlist[n-1], wlist, n-1):
        return True
    if knap_rec(weight, wlist, n-1):
        return True
    else:
        return False


if __name__ == '__main__':
    s = SStack()
    assert s.is_empty() is True
    try:
        s.pop()
    except StackUnderflow:
        print("StackUnderflow")
    s.push(123)
    assert s.is_empty() is not True
    assert s.pop() == 123
    assert check_parens("[{1232}]") is True
    assert check_parens("[{[}]") is False
    assert check_parens("[{123444]}]") is False
    assert check_parens("][{}]") is False
    assert knap_rec(40, [90, 40, 20, 10], 4) is True
