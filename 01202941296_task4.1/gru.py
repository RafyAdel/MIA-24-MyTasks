from task1 import villan
from weapon import weapons
from weapon import shield

class Gru(villan,weapons,shield):
    def __init__(self,weapon,shield):
        self.weapon=""
        self.shield=""

    def setweapon(self,weapon):
        self.weapon=weapon
    def setshield(self,shield):
        self.shield=shield

    def getweappon(self):
        return self.weapon
    def getshield(self):
        return self.shield
                
class vector(villan,weapons,shield):
    def __init__(self,weapon,shield):
        self.weapon=""
        self.shield=""  

    def setweapon(self,weapon):
        self.weapon=weapon
    def setshield(self,shield):
        self.shield=shield

    def getweappon(self):
        return self.weapon
    def getshield(self):
        return self.shield