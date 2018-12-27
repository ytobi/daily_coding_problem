import argparse

def check_comand_line_args():

    parser = argparse.ArgumentParser( description=
    "Enter two to calculate their edit distance")

    parser.add_argument("-s1", "--string1", dest="string1", required=True,
    help="First string to compare" )
    parser.add_argument("-s2", "--string2", dest="string2", required=True,
    help="Second string to compare" )

    # Return command line argument
    return parser.parse_args()


def main():
    args = check_comand_line_args()

    string1 = args.string1
    string2 = args.string2

    distance = len(string1) - len(string2)

    if distance < 0:
        distance //= -1

    for s1, s2 in zip(string1, string2):
        if s1 != s2:
            distance += 1
    
    print( 'Total edit distance between ', string1, ' and ', string2, ' is ', distance )

main()