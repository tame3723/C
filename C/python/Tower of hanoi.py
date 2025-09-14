def tower_of_hanoi(n):
    # Peg names: A = source, B = support, C = destination
    A, B, C = 'A', 'B', 'C'

    # If n is even, we swap support (B) and destination (C)
    if n % 2 == 0:
        B, C = C, B

    # Total number of moves: 2^n - 1
    total_moves = 2 ** n - 1

    # starting pegs define
    source = list(range(n, 0, -1))
    support = []
    destination = []

    # peg names dict
    pegs = {A: source, B: support, C: destination}

    # Moves
    def print_move(from_peg, to_peg, disk):
        print(f"Move disk {disk} from {from_peg} to {to_peg}")

    # for Legal move
    def legal_move(peg1, peg2, from_peg_name, to_peg_name):
        if pegs[peg1] and (not pegs[peg2] or pegs[peg1][-1] < pegs[peg2][-1]):
            disk = pegs[peg1].pop()
            pegs[peg2].append(disk)
            print_move(peg1, peg2, disk)
        else:
            disk = pegs[peg2].pop()
            pegs[peg1].append(disk)
            print_move(peg2, peg1, disk)

    # loop for total_moves
    for move in range(1, total_moves + 1):
        if move % 3 == 1:
            legal_move(A, C, A, C)  # Move between source and destination
        elif move % 3 == 2:
            legal_move(A, B, A, B)  # Move between source and support
        elif move % 3 == 0:
            legal_move(B, C, B, C)  # Move between support and destination

# Example usage:
n = 4  # Number of disks
tower_of_hanoi(n)
