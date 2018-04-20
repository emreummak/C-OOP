import random
class Kumanda():
    def __init__(self,tvdurum="kapali",kanal="trt",kanal_listesi=["trt"],ses=0):
        self.tvdurum=tvdurum
        self.kanal=kanal
        self.kanal_listesi=kanal_listesi
        self.ses=ses
    def __str__(self):
        return "Tv durumu: {}\nKanal: {}\nKanal listesi: {}\nSes: {}".format(self.tvdurum,self.kanal,self.kanal_listesi,self.ses)
    def __len__(self):
        return len(self.kanal_listesi)
    def tvdurumu(self):
        if self.tvdurum=="kapali":
            self.tvdurum="acik"
            print(self.tvdurum)
        else:
            self.tvdurum="kapali"
            print(self.tvdurum)
    def kanal_ekle(self):
        if self.tvdurum=="acik":
            kanal_adi=input("Kanal adi girin: ")
            self.kanal_listesi.append(kanal_adi)
        else:
            print("Once tv yi acmaniz gerekmektedir.")
    def sesayarla(self):
        if self.tvdurum=="acik":
            ses=""
            while ses!="c":
                ses = input("> veya <: (cikmak icin 'c')")
                if ses==">":
                    if self.ses<31:
                        self.ses+=1
                        print(self.ses)
                    elif self.ses==31:
                        print("Max ses düzeyi")
                elif ses=="<":
                    if self.ses>0:
                        self.ses-=1
                        print(self.ses)
                    elif self.ses==0:
                        print("Min ses düzeyi")
            else:
                print("Once tv yi acmaniz gerekmektedir.")
    def kanalgetir(self):
        kanalsayi=random.randint(0,len(self.kanal_listesi)-1)
        self.kanal=self.kanal_listesi[kanalsayi]
        print(self.kanal)
kumanda = Kumanda()
while True:
    tus=int(input("""
    1-)Tv ac-kapat
    2-)Kanal ekle
    3-)Ses ayarla
    4-)Durumu getir
    5-)Kanal sayisi getir
    6-)Kanal degistir
    0-)Cikis
    Yapilmasini istediğiniz islemi giriniz: """))
    if tus==1:
        kumanda.tvdurumu()
    elif tus==2:
        while True:
            kanalal=int(input("Kanal girmek icin 1 cikmak icin 0 basin: "))
            if kanalal==1:
                kumanda.kanal_ekle()
            elif kanalal==0:
                break
    elif tus==3:
        kumanda.sesayarla()
    elif tus==4:
        print(kumanda)
    elif tus==5:
        print(len(kumanda))
    elif tus==6:
        kumanda.kanalgetir()
    elif tus==0:
        break
    else:
        print("hatali bir tusa bastiniz")









