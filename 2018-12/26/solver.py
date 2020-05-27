import argparse

def check_comand_line_args():

    parser = argparse.ArgumentParser( description=
    "Description is a bit long, check the readme for this exercise")

    parser.add_argument("-l", "--list", dest="llist",  nargs='+', required=True,
    help="The list we will be working with eg [1, 2, ..., n]" )
   
    # Return command line argument
    return parser.parse_args()


def main():
    args = check_comand_line_args()

    llist = ''.join(args.llist)
    llist = llist.strip('[')
    llist = llist.strip(']')

    highest = int(llist[0])
    total = 0
    
    for i in llist:
        if i.isdigit():
            if int(i) >= highest:
                highest = int(i)
            else:
                total += highest - int(i)

    
    print( 'Total unit of water trapped is: ', total )

main()