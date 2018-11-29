# -*- coding: UTF-8 -*-
import datetime

from PersonTypeError import PersonTypeError
from PersonValueError import PersonValueError


class Person:
    _num = 0

    def __init__(self, name, sex, birthday, ident):
        if not (isinstance(name, str)) and sex in ("女", "男"):
            raise PersonTypeError(name, sex)
        try:
            birth = datetime.date(*birthday)
        except ValueError:
            raise PersonValueError("Wrong date:", birthday)
        self._name = name
        self._sex = sex
        self._birthday = birth
        self._id = ident
        Person._num += 1

    def set_name(self, name):
        if not (isinstance(name, str)):
            raise PersonTypeError(name)
        self._name = name

    @classmethod
    def num(cls):
        return cls._num

    def __str__(self):
        return " ".join((self._id, self._name, self._sex, str(self._birthday)))


person = Person('test', '男', (1995, 10, 13), '1')
person2 = Person('test', '男', (1995, 10, 13), '1')
print(person)
