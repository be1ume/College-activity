#Mariano - BSCS-1A

students = []

def ave(x,y,z):
    return (x+y+z) / 3.00

def add_rec(name, x, y, z):
    for rec in students:
        if name == rec["name"]:
            print("Record Already Exist!")
            return

    record = {
        "name": name,
        "q1": x,
        "q2": y,
        "q3": z
    }
    students.append(record)
    print(f"Record of {name} added successfully!")
    return

def del_rec(name):
    for rec in students:
        if rec["name"] == name:
            students.remove(rec)
            print(f"Record of {name} deleted successfully")
            return
    print(f"Record of {name} not found!")
    return

def update_rec(name):
    located = False
    for i, rec in enumerate(students):
        if rec["name"] == name:
            located = True
            while True:
                try:
                    print("=====UPDATING RECORD=====\n"
                          f"Name: {rec["name"]}\n"
                          f"1. Quiz 1: {rec["q1"]}\n"
                          f"2. Quiz 2: {rec["q2"]}\n"
                          f"3. Quiz 3: {rec["q3"]}\n"
                          "4. Exit"
                          )
                    opt = int(input("Choose [1-4]: "))

                    match (opt):
                        case 1:
                            updated_q1 = int(input("Enter New Value of Quiz 1: "))
                            rec["q1"] = updated_q1
                            print("Quiz 1 updated successfully!")
                        case 2:
                            updated_q2 = int(input("Enter New Value of Quiz 2: "))
                            rec["q2"] = updated_q2
                            print("Quiz 2 updated successfully!")
                        case 3:
                            updated_q3 = int(input("Enter New Value of Quiz 3: "))
                            rec["q3"] = updated_q3
                            print("Quiz 3 updated successfully!")
                        case 4:
                            break
                        case _:
                            print("Invalid option!")
                except ValueError:
                    print("Invalid option!")
            break
    if not located:
        print(f"Record of {name} not found!")
        return

def display_rec(name):
    for rec in students:
        if name == rec["name"]:
            print(f"=====Record of {name}=====\n"
                  f"Name: {rec["name"]}\n"
                  f"Quiz 1: {rec["q1"]}\n"
                  f"Quiz 2: {rec["q2"]}\n"
                  f"Quiz 3: {rec["q3"]}"
                  )
            return
    print(f"Record of {name} not found!")

def display():
    print("{:<3} {:<10} {:<10} {:<10} {:<10} {:<10} {:<10}".format("ID", "NAME", "QUIZ1", "QUIZ2", "QUIZ3", "AVERAGE", "REMARKS"))

    for index, rec in enumerate(students):
        print("{:<3} {:<10} {:<10} {:<10} {:<10} {:<10} {:<10}".format\
        (index+1, rec["name"], rec["q1"], rec["q2"],
        rec["q3"], ave(rec["q1"], rec["q2"], rec["q3"]),
        "PASSED" if ave(rec["q1"], rec["q2"], rec["q3"]) >= 75 else "FAILED"))

def menu():
    print("1. Add Record\n"
          "2. Update Record\n"
          "3. Delete Record\n"
          "4. Display a Record\n"
          "5. Display All\n"
          "6. Exit")
    try:
        option = int(input("Choose [1-6]: "))
        return option
    except ValueError:
        print("Invalid option!")
        return


while True:
    match (menu()):
        case 1:
            student = input("Enter Name: ")
            try:
                q1 = int(input("Enter Quiz 1: "))
                q2 = int(input("Enter Quiz 2: "))
                q3 = int(input("Enter Quiz 3: "))
                add_rec(student, q1, q2, q3)
            except ValueError:
                print("Invalid input!")
        case 2:
            for_update = input("Enter Student to Update: ")
            update_rec(for_update)
        case 3:
            for_deletion = input("Enter Name for Deletion: ")
            del_rec(for_deletion)
        case 4:
            for_display_rec = input("Enter Student to View: ")
            display_rec(for_display_rec)
        case 5:
            display()
        case 6:
            break
        case _:
            print("Invalid option!")
