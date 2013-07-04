#-------------------------------------------------------------------------------
# Name:        module2
# Purpose:
#
# Author:      Student
#
# Created:     02/07/2013
# Copyright:   (c) Student 2013
# Licence:     <your licence>
#-------------------------------------------------------------------------------

def main():
    class Player:
        first_name = None
        last_name = None
        username = None
        age = None
        level = None

        def get_info(self):
            print "Enter First Name:"
            self.first_name = raw_input("> ")

            print "Enter Last Name:"
            self.last_name = raw_input("> ")

            print "Enter Username:"
            self.username = raw_input("> ")

            print "Enter Age:"
            self.age = int(raw_input("> "))

            print "Enter Level:"
            self.level = int(raw_input("> "))

        def display_info(self):
            print "Player Information:"
            print "Name: {0} {1}".format(self.first_name, self.last_name)
            print "Username: ", self.username
            print "Age: ", self.age
            print "Level: ", self.level

        def level_up(self):
            self.level = self.level + 1

        def battle_cry(self):


if __name__ == '__main__':
        main()