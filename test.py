import json as js
from os import system
from copy import deepcopy

class Player:
    def __init__(self):
        self.__pool = 30
        self.__attribute = {
            'Strength' : 0,
            'Health' : 0,
            'Wisdom' : 0,
            'Dexterity' : 0,
        }

    def Attribute(self,attr=None):
        """
        Return the Attrubute of Player. You can specify what attribute you want.

        Parameter:
            attr=None: You can specify what attribute you want
        """
        if attr is not None:
            try:
                return "{} : {}".format(attr,self.__attribute[attr])
            except KeyError as e:
                print('This attr is not in Players\' attributes')
        else:
            return js.dumps(self.__attribute,indent=4)

    def Add(self,attr:str(),num:int = 0):
        """
        Add the attribute

        Parameter:

            attr(str) : attribute
            num : How many point you want to add to the player's attribute.Default is zero.
        """
        if(num > self.__pool):
            print('Point is not enough')
        else:
            try:
                self.__attribute[attr] += num
            except KeyError as e:
                print('This attr is not in Players\' attributes')
                return
            self.__pool -= num
        
    def Subtract(self,attr:str(),num:int):
        """
        Subtract the attribute

        Parameter:

            attr(str) : attribute
            num : How many point you want to subtract to the player's attribute.Default is zero.
        """

        if(num > self.__attribute[attr]):
            print('Point is not enough')
        
        else:
            try:
                self.__attribute[attr] -= num
            except KeyError as e:
                print('This attr is not in Players\' attributes')
                return
            self.__pool += num
        
    def __str__(self)->str:
        attr = js.dumps(self.__attribute,indent=4)
        return 'Pool = {}'.format(self.__pool) + '\n' + 'Attribute = '+attr

    def __repr__(self):
        return self.__str__()

    def Pool(self):
        return self.__pool


def Add(player:Player):
    print('Which ability do you want : ')
    print(
        """
        Strength
        Health
        Wisdom
        Dexterity
        """
    )
    inp = input()
    num = int(input('How many point do you wnat to add '))

    player.Add(inp,num)
    return player

def Subtract(player:Player):
    print('Which ability do you want : ')
    print(
        """
        Strength
        Health
        Wisdom
        Dexterity
        """
    )
    inp = input()
    num = int(input('How many point do you wnat to subtract '))
    player.Subtract(inp,num)
    return player


def main():
    player = Player()

    while(player.Pool()!=0):
        print(
            """
            0 - Quit
            1 - Add Point
            2 - Subtract Point
            """
        )
        inp = input()
        if inp == '0':
            exit()
        elif inp == '1':
            player = Add(player)
        elif inp == '2':
            player = Subtract(deepcopy(player))
        print('-'*80)
        print(player)
        print('-'*80)


if __name__ == '__main__':
    main()