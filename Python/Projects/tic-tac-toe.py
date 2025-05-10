#Mariano BSCS-1A

def print_board(board):
    print("\n"+"-" *10)
    for row in board:
        print(" | ".join(row))
        print("-" * 10)

def check_winner(board, player):
    for i in range(3):
        if all([cell == player for cell in board[i]]):
            return True
        if all([board[j][i] == player for j in range(3)]):
            return True
    if all([board[i][i] == player for i in range(3)]):
        return True
    if all([board[i][2 - i] == player for i in range(3)]):
        return True
    return False

def is_full(board):
    return all(cell != '-' for row in board for cell in row)

def computer_try_to_win(board):
    for i in range(3):
        for j in range(3):
            if board[i][j] == '-':
                board[i][j] = 'O'
                if check_winner(board, 'O'):
                    return True
                board[i][j] = '-'

def computer_block(board):
    for i in range(3):
        for j in range(3):
            if board[i][j] == '-':
                board[i][j] = 'X'
                if check_winner(board, 'X'):
                    board[i][j] = 'O'
                    return True
                board[i][j] = '-'

def computer_take_center(board):
    if board[1][1] == '-':
        board[1][1] = 'O'
        return True
    else:
        return False

def computer_take_corner(board):
    if board[0][0] == '-':
        board[0][0] = 'O'
        return True
    elif board[0][2] == '-':
        board[0][2] = 'O'
        return True
    elif board[2][0] == '-':
        board[2][0] = 'O'
        return True
    elif board[2][2] == '-':
        board[2][2] = 'O'
        return True
    else:
        return False

def computer_take_edge(board):
    if board[0][1] == '-':
        board[0][1] = 'O'
        return
    elif board[1][0] == '-':
        board[1][0] = 'O'
        return
    elif board[1][2] == '-':
        board[1][2] = 'O'
        return
    elif board[2][1] == '-':
        board[2][1] = 'O'
        return
    else:
        return False

def computer_turn(board):
    if computer_try_to_win(board):
        return
    elif computer_block(board):
        return
    elif computer_take_center(board):
        return
    elif computer_take_corner(board):
        return
    elif computer_take_edge(board):
        return

def play_game():
    board = [['-' for _ in range(3)] for _ in range(3)]
    current_player = 'X'

    while True:
        print_board(board)
        if current_player == "X":
            try:
                row = int(input(f"Player {current_player}, enter row (1-3): ")) - 1
                col = int(input(f"Player {current_player}, enter column (1-3): ")) - 1
            except ValueError:
                print("Please enter valid numbers.")
                continue

            if row not in range(3) or col not in range(3):
                print("Row and column must be between 1 and 3.")
                continue
            if board[row][col] != '-':
                print("Cell already taken. Try again.")
                continue

            board[row][col] = current_player
        else:
            computer_turn(board)

        if check_winner(board, current_player):
            print_board(board)
            print(f"🎉 Player {current_player} wins!")
            break
        elif is_full(board):
            print_board(board)
            print("It's a draw!")
            break

        current_player = 'O' if current_player == 'X' else 'X'

play_game()
