class ISorted:
    def iterative_sorted(self, arr):
        return all(arr[i] >= arr[i + 1] for i in range(len(arr) - 1))


class ROccurrence:
    def r_occurance_number(self, arr, target):
        if not arr:
            return 0
        return (1 if arr[-1] == target else 0) + self.r_occurance_number(arr[:-1], target)


class Smallest:
    def i_smallest(self, arr):
        if not arr:
            return None
        return min(arr)

    def r_smallest(self, arr):
        if not arr:
            return None
        if len(arr) == 1:
            return arr[0]
        min_val = self.r_smallest(arr[:-1])
        return min(min_val, arr[-1])


class Palindrome:
    def i_palindrome(self, arr):
        return arr == arr[::-1]

    def r_palindrome(self, arr, left, right):
        if left >= right:
            return True
        if arr[left] != arr[right]:
            return False
        return self.r_palindrome(arr, left + 1, right - 1)


class PracticeProblems:
    def __init__(self):
        self.sortcheck = ISorted()
        self.occurance = ROccurrence()
        self.small = Smallest()
        self.palindromechecker = Palindrome()

    def menu(self):
        print("----------------------------Practice Problems-----------------------------")
        print("1. Iterative method to determine if array is sorted in descending order.")
        print("2. Recursive method to count the occurrence of a number in an array")
        print("3. Iterative method to find the smallest element in an array")
        print("4. Recursive method to find the smallest element in an array")
        print("5. Iterative method to check if the array is PALINDROME")
        print("6. Recursive method to check if the array is PALINDROME")
        print("7. Change the array")
        print("8. Exit")
        print("--------------------------------------------------------------------------")
        opt = int(input("[1-8]-> "))
        return opt

    def input_array(self, length):
        arr = []
        for i in range(length):
            val = int(input(f"Element {i + 1}: "))
            arr.append(val)
        return arr

    def cases(self):
        arr = []
        len_arr = 0

        while True:
            if len_arr == 0:
                len_arr = int(input("Enter size of your array (max 10): "))
                arr = self.input_array(len_arr)

            option = self.menu()
            if option == 1:
                print("--Check if the array is sorted in descending order.--")
                print(f"Your array is {arr}")
                if self.sortcheck.iterative_sorted(arr):
                    print("The array is sorted in descending order.")
                else:
                    print("The array is not sorted in descending order.")
            elif option == 2:
                print(f"Your array is {arr}")
                target = int(input("Enter target number: "))
                print(f"The number {target} occurred {self.occurance.r_occurance_number(arr, target)} times!")
            elif option == 3:
                print(f"Your array is {arr}")
                print(f"The smallest element in your array is {self.small.i_smallest(arr)}")
            elif option == 4:
                print(f"Your array is {arr}")
                print(f"The smallest element in your array is {self.small.r_smallest(arr)}")
            elif option == 5:
                print(f"Your array is {arr}")
                if self.palindromechecker.i_palindrome(arr):
                    print("The array is a palindrome!")
                else:
                    print("The array is not a palindrome!")
            elif option == 6:
                print(f"Your array is {arr}")
                if self.palindromechecker.r_palindrome(arr, 0, len(arr) - 1):
                    print("The array is a palindrome!")
                else:
                    print("The array is not a palindrome!")
            elif option == 7:
                len_arr = int(input("Enter size of your array (max 10): "))
                arr = self.input_array(len_arr)
            elif option == 8:
                break
            else:
                print("Invalid Input!")

if __name__ == "__main__":
    practice_problems = PracticeProblems()
    practice_problems.cases()
