class weapons():
    def __init__(self,WeaponName,weaponenergy,damage,resources):
        self.WeaponName=""
        self.weaponenergy=""
        self.damage=""
        self.resources=""

    def setWeaponName(self,WeaponName):
        self.WeaponName=WeaponName
    def setweaponenergy(self,weaponenergy):
        self.weaponenergy=weaponenergy
    def setdamage(self,damage):
        self.damage=damage
    def setresources(self,resources):
        self.resources=resources

    def getWeaponName(self):
        return self.WeaponName
    def getweaponenergy(self):
        return self.weaponenergy
    def getdamage(self):
        return self.damage
    def getresources(self):
        return self.resources

class shield():
    def __init__(self,shieldName,shieldenergy,save,shieldresources):
        self.shieldName=""
        self.shieldenergy=""
        self.save=""
        self.shieldresources=""

    def setshieldname(self,shieldname):
        self.shieldname=shieldname
    def setshieldenergy(self,shieldenergy):
        self.shieldenergy=shieldenergy
    def setsave(self,save):
        self.save=save
    def setrshieldesources(self,shieldresources):
        self.shieldresources=shieldresources

    def getshieldname(self):
        return self.shieldName
    def getshieldenergy(self):
        return self.shieldenergy
    def getsave(self):
        return self.save
    def getrshieldesources(self):
        return self.shieldresources