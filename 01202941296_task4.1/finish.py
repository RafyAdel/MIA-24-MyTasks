from gru import *
print("START battle !")
v1 = Gru("weapon","shield")
v2=vector("weapon","shield")
v1.setname("gru")
v1.setenergy(500)
v1.sethealth(100)
v2.setname("vector")
v2.setenergy(500)
v2.sethealth(100)
i=1 
a=b=c=d=e=f=g=0 #resources counter

while (v1.health != 0) :
    if v2.health !=0:
        
        print("round ",i,"\n")
        ws=input ("let's start with Gru\ndo you want a weapon or a shield ?\n")
        if ws=="weapon":
            v1.setweapon("true")
            v2.setshield("true")
            v1.setWeaponName(input("plz select one from:\n(Freeze Gun, Electric Prod, Mega Magnet, Kalman Missile)"))  
            if v1.WeaponName=="Freeze Gun":
                v1.setweaponenergy(50)
                v1.setdamage(11)
                v1.setresources("inf")
            elif (v1.WeaponName=="Electric Prod") and (a!=5):
                v1.setweaponenergy(88)
                v1.setdamage(18)
                v1.setresources(5)
                a=a+1
            elif v1.WeaponName=="Mega Magnet" and b!=3 :
                v1.setweaponenergy(92)
                v1.setdamage(10)
                v1.setresources(3)
                b=b+1
            elif v1.WeaponName=="Kalman Missile" and c!= 1:
                v1.setweaponenergy(120)
                v1.setdamage(20)
                v1.setresources(1)                
                c=c+1
            else: print("wrong choice ! close program\n");break
            print("let's continue with vector\nu have to choose a shield for this round\n")
            print("plz select one from:\n")
            v2.setshieldname (input("(Energy Net Trape, Quantum Deflector)"))
            if v2.shieldname=="Energy Net Trape":
                v2.setshieldenergy(15)
                v2.setsave(0.32*v1.damage)
                v2.setrshieldesources("inf")
            elif v2.shieldname=="Quantum Deflector" and d!=3:
                v2.setshieldenergy(40)
                if v1.WeaponName=="Kalman Missile":
                    v2.setsave(0)
                else: v2.setsave(0.8*v1.damage)    
                v2.setrshieldesources(3)  
                d=d+1
            else:print("wrong choice!close program\n");break    
            v2.setenergy(500-(v2.shieldenergy))
            v1.setenergy(500-v1.weaponenergy)
        elif ws=="shield":
            v1.setshield("true")
            v2.setweapon("true")
            print("since Gru chose a shield so let,s know vector's weapon first\n")
            v2.setWeaponName(input("plz select one from:\n(Laser Blaster, Plasma Grenades, Sonic Resonance Cannon)\n"))  
            if v2.WeaponName=="Laser Blaster":
                v2.setweaponenergy(40)
                v2.setdamage(8)
                v2.setresources("inf")
            elif (v2.WeaponName=="Plasma Grenades") and (e!=8):
                v2.setweaponenergy(56)
                v2.setdamage(13)
                v2.setresources(8)
                e=e+1
            elif v2.WeaponName=="Sonic Resonance Cannon" and f!=3 :
                v2.setweaponenergy(100)
                v2.setdamage(22)
                v2.setresources(3)
                f=f+1
            else: print("wrong choice ! close program\n");break
            print("let's continue with Gru\nu will choose a shield for this round\n")            
            v1.setshieldname(input("so plz select one from:\n(Energy-Projected BarrierGun, Selective Permeability)"))    
            if v1.shieldname=="Energy-Projected BarrierGun":
                v1.setrshieldresources("inf")
                v1.setshieldenergy(20)
                v1.setsave(0.2*v2.damage)
            elif v1.shieldname=="Selective Permeability" and g!=2:
                v1.setshieldresources(2)
                v1.setshieldenergy(50)
                v1.setsave(0.9*v2.damage)                   
                g=g+1
            else:print("wrong choice ! close program\n");break 
            y=500-v1.getshieldenergy   
            v1.setenergy(y)
            v2.setenergy(500-v2.getweaponenergy)
        else:
            print("doesn't match ! close battle");break
        
        print("the results of round",i,":\n")
        v1.sethealth(100-v1.save)
        v2.sethealth(100-v2.save)
        print("Gru: health energy weapon shield\n     ")
        v1.gethealth() ; v1.getenergy() ; v1.getWeaponName() ; v1.getshieldname()
        print("vector: health energy weapon shield\n        ")
        v2.gethealth() ; v2.getenergy() ; v2.getWeaponName() ; v2.getshieldname()
        i=i+1
    else:break          
            
        
        



    
    
