import os
MAX = 5

class StudentRecord:
    def __init__(self, name, q1, q2, q3):

        self.name = name
        self.q1 = int(q1)
        self.q2 = int(q2)
        self.q3 = int(q3)

    def __str__(self):
        ave = (self.q1 + self.q2 + self.q3)/3
        remark = "PASSED" if ave >= 75 else "FAILED"
        return f"{self.name}\t{self.q1}\t{self.q2}\t{self.q3}\t{ave:.2f}\t{remark}"

    def to_csv(self):
        return f"{self.name},{self.q1},{self.q2},{self.q3}"

    @staticmethod
    def from_csv(line):
        parts = line.strip().split(',')
        if len(parts) == 4:
            name, q1, q2, q3 = parts
            return StudentRecord(name, q1, q2, q3)
        return None

class Record:
    def __init__(self, filename="objectsRec.txt"):
        self.student = []
        self.filename = filename
        self.load_rec()

    def find_student(self, name):
        for i, rec in enumerate(self.student):
            if rec.name == name:
                return i
        return -1

    def is_full(self):
        return len(self.student) >= MAX

    def add_rec(self, name, q1, q2, q3):
        if self.is_full():
            print("Maximum record reached. . .")
            os.system('pause')
            os.system('cls' if os.name == 'nt' else 'clear')
        elif self.find_student(name) != -1:
            print("Student already exist. . .")
            os.system('pause')
            os.system('cls' if os.name == 'nt' else 'clear')
        else:
            self.student.append(StudentRecord(name, q1, q2, q3))
            print("Record append successfully. . .")
            os.system('pause')
            os.system('cls' if os.name == 'nt' else 'clear')

    def del_rec(self, name):
        index = self.find_student(name)
        if index == -1:
            print("Account doesnt exist")
            os.system('pause')
        else:
            print(f"Record of {self.student[index].name} deleted successfully. . .")
            del self.student[index]
            os.system('pause')
            os.system('cls' if os.name == 'nt' else 'clear')
            self.save_record()

    def display_all(self):
        print("ID\tNAME\tQUIZ1\tQUIZ2\tQUIZ3\tAVERAGE\tREMARKS")
        for index, rec in enumerate(self.student):
            print(f"{index+1}\t{rec}")
        os.system('pause')


    def save_record(self):
        try:
            with open(self.filename, 'w') as file:
                for rec in self.student:
                    file.write(rec.to_csv() + '\n')
            print("Record stored upon exiting. . .")
        except IOError:
            print("Error saving record to file. . .")

    def load_rec(self):
        try:
            with open(self.filename, 'r') as file:
                for line in file:
                    record = StudentRecord.from_csv(line)
                    if record:
                        self.student.append(record)
        except FileNotFoundError:
            pass
        except IOError:
            print("Error reading accounts from file. . .")

def menu():
    print("1. Add a Record\n2. Delete a Record\n3. Display all\n4.Exit\n")
    try:
        return int(input("Enter 1-4: "))
    except ValueError:
        print("Invalid option. . .")

def main():
    record = Record()
    while True:
        os.system('cls' if os.name == 'nt' else 'clear')
        match(menu()):
            case 1:
                os.system('cls' if os.name == 'nt' else 'clear')
                name = input("Enter Name: ")
                try:
                    q1 = int(input("Enter Quiz 1: "))
                    q2 = int(input("Enter Quiz 2: "))
                    q3 = int(input("Enter Quiz 3: "))
                    record.add_rec(name, q1, q2, q3)
                except ValueError:
                    print("Invalid input!")
            case 2:
                os.system('cls' if os.name == 'nt' else 'clear')
                name = input("Enter student name to delete a record: ")
                record.del_rec(name)
            case 3:
                os.system('cls' if os.name == 'nt' else 'clear')
                record.display_all()
            case 4:
                record.save_record()
                print("Program terminated. . .")
                break
            case _:
                print("Invalid option. . .")
                os.system('pause')
                os.system('cls' if os.name == 'nt' else 'clear')

if __name__ == "__main__":
    main()