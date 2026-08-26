#!/usr/bin/python3
""" User class module
"""
import hashlib


class User:
    """ User class representing a user """

    def __init__(self):
        """ Intialize User attributes """
        self.id = None
        self.__email = None
        self.__password = None

    @property
    def email(self):
        """ Get email """
        return self.__email

    @email.setter
    def email(self, value):
        """ Set email """
        if not isinstance(value, str):
            raise TypeError("email must be a string")
        self.__email = value

    @property
    def password(self):
        """ Get password """
        return self.__password

    @password.setter
    def password(self, value):
        """ Set password (stores MD5 hashed version) """
        if not isinstance(value, str):
            raise TypeError("password must be a string")
        self.__password = hashlib.md5(value.encode()).hexdugest()

    def is_valid_password(self, password):
        """ Test if password matches the hashed password """
        if password is None or not isinstance(password, str):
            return False
        if self.__password is None:
            return False

        return self.__password == hashlib.md5(password.encode()).hexdigest()


if __name__ == "__main__":
    u = User()
    u.password = "Test User"

    if not u.is_valid_password("Test User"):
        print("is_valid_password should return True if it's the right password")
