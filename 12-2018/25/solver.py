import argparse

def check_comand_line_args():

    parser = argparse.ArgumentParser( description=
    "Run length encoding, take a String of char only and run  length encode them")

    parser.add_argument("-e", "--encode", dest="encode", help="Pass string to runlength encode" )

    parser.add_argument("-d", "--decode", dest="decode", help="Pass string to runlength decode" )

    args = parser.parse_args()

    if( args.encode == None and args.decode == None ):
        print('\n', 'You must either pass in a string to encode or decode' ,'\n\n')
        parser.print_help()
        exit(0)
   
    # Return command line argument
    return parser.parse_args()


def encode( s ):
    encoded = ''
    prev = s[0]
    occurence = 0

    for i in range(len(s)):
        if s[i] == prev:
            occurence += 1
        else:
            prev = s[i]
            encoded += str(occurence) + s[i-1]
            occurence = 1
    
    encoded += str(occurence) + prev        
    return encoded


def decode( s ):

    decoded = ''

    for i in range(len(s)):
        if s[i].isdigit():
            for t in range(int(s[i])):
                decoded += s[i+1]
            i += 2
    
    return decoded

def main():

    args = check_comand_line_args()

    encoded = ''
    decoded = ''

    if( args.encode != None ):
        encoded = encode( args.encode )
        print( args.encode, '--encode->', encoded )
    if( args.decode != None ):
        decoded = decode( args.decode )
        print( decoded, '<-decode--', args.decode )

main()