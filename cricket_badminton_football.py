# Function to accept group data
def accept_group():
    group = input("Enter student names separated by space: ").split()
    return group

def get_students_playing_both(cricket_players, badminton_players):
    """Returns a list of students playing both cricket and badminton."""
    both_players = []
    for player in cricket_players:
        if player in badminton_players:
            both_players.append(player)
    return both_players

def get_students_playing_either(cricket_players, badminton_players):
    """Returns a list of students playing either cricket or badminton but not both."""
    either_players = []
    for player in cricket_players:
        if player not in badminton_players:
            either_players.append(player)
    for player in badminton_players:
        if player not in cricket_players:
            either_players.append(player)
    return either_players

def get_students_playing_neither(all_students, cricket_players, badminton_players):
    """Returns the number of students playing neither cricket nor badminton."""
    neither_players = 0
    for player in all_students:
        if player not in cricket_players and player not in badminton_players:
            neither_players += 1
    return neither_players

def get_students_playing_cricket_and_football(cricket_players, football_players, badminton_players):
    """Returns the number of students playing cricket and football but not badminton."""
    count = 0
    for player in cricket_players:
        if player in football_players and player not in badminton_players:
            count += 1
    return count

# Get student names as input
print("Enter Names Of all students")
all_students = accept_group()
print("Enter Names Of Students Who playes CRICKET")
cricket_players = accept_group()
print("Enter Names Of Students Who playes BADMINTON")
badminton_players = accept_group()
print("Enter Names Of Students Who playes FOOTBALL")
football_players = accept_group()

# Calculate and print results
both_players = get_students_playing_both(cricket_players, badminton_players)
either_players = get_students_playing_either(cricket_players, badminton_players)
neither_players = get_students_playing_neither(all_students, cricket_players, badminton_players)
cricket_and_football_players = get_students_playing_cricket_and_football(cricket_players, football_players, badminton_players)

print("Students playing both cricket and badminton:", both_players)
print("Students playing either cricket or badminton but not both:", either_players)
print("Number of students playing neither cricket nor badminton:", neither_players)
print("Number of students playing cricket and football but not badminton:", cricket_and_football_players)