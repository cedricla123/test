moyenne = input("Entrez une moyenne : ")
moyenne = float(moyenne)
if 0 <= moyenne <= 20:
    if 0 <= moyenne <= 4:
        print("MENTION : NULL")
    elif 4 < moyenne <= 8:
        print("MENTION : INSSUFISANT")
    elif 8 < moyenne < 10:
        print("MENTION : MEDIOCRE")
    elif 10 <= moyenne < 12:
        print("MENTION : PASSABLE")
    elif 12 <= moyenne < 14:
        print("MENTION : ASSEZ BIEN")
    elif 14 <= moyenne < 16:
        print("MENTION : BIEN")
    elif 16 <= moyenne <= 18:
        print("MENTION : TRES BIEN")
    else:
        print("MENTION : EXCELLENT")
else:
    print("Entrez une moyenne valide :( ")