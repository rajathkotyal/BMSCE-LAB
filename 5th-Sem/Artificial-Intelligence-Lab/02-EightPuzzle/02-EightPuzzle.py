import random
import math

def main():
    print ( "Initial state of the puzzle" )
    p = puzzle_3_x_3()
    p.shuffle( 30 )
    print ( p )

    path, count = p.solve( h_manhattan )
    path.reverse()
    count_moves = 1

    for i in path:
        print ( "Movement " , count_moves )
        print ( i )
        count_moves += 1

final_state =   [   [ 0 , 1 , 2 ] ,
			    	[ 3 , 4 , 5 ] ,
				    [ 6 , 7 , 8 ] ]

class puzzle_3_x_3:
    def __init__( self ):
        self.heuristic_value = 0
        self.depth = 0
        self.father = None
        self.adjacent = []
        for i in range( 3 ):
            self.adjacent.append( final_state[ i ][ : ] )

    def __eq__( self, other ):
        if self.__class__ != other.__class__:
            return False

        else:
            return self.adjacent == other.adjacent

    def __str__( self ):
        res = ''
        for row in range( 3 ):
            res += ' '.join( map( str, self.adjacent[ row ] ) )
            res += '\r\n'

        return res

    def make_copy( self ):
        p = puzzle_3_x_3()
        for i in range( 3 ):
            p.adjacent[ i ] = self.adjacent[ i ][ : ]

        return p

    def find_valid_moviment( self ):
        row, col = self.find( 0 )
        free_space = []

        if( row > 0 ):
            free_space.append( ( row - 1, col ) )

        if( col > 0 ):
            free_space.append( ( row, col - 1 ) )

        if( row < 2 ):
            free_space.append( ( row + 1, col ) )

        if( col < 2 ):
            free_space.append( ( row, col + 1 ) )

        return free_space

    def generate_movement( self ):
        free_space = self.find_valid_moviment()
        zero = self.find( 0 )

        def copy_and_move( a, b ):
            p = self.make_copy()
            p.change( a, b )
            p.depth = self.depth + 1
            p.father = self

            return p

        return map( lambda pair: copy_and_move( zero, pair ), free_space )

    def generate_solution_path( self, path ):
        if self.father == None:
            return path

        else:
            path.append( self )
            return self.father.generate_solution_path( path )

    def solve( self, h ):
        def solved( puzzle ):
            return puzzle.adjacent == final_state

        starting = [ self ]
        finishing = []
        counter = 0

        while len( starting ) > 0:
            x = starting.pop( 0 )
            counter += 1

            if( solved( x ) ):
                if( len( finishing ) > 0 ):
                    return x.generate_solution_path( [] ), counter

                else:
                    return [ x ]

            successor = x.generate_movement()
            opend_index = closed_index = -1

            for make_movement in successor:
                opend_index = index( make_movement, starting )
                closed_index = index( make_movement, finishing )
                heuristic_value = h( make_movement )
                final_value = heuristic_value + make_movement.depth

                if( closed_index == -1 and opend_index == -1 ):
                    make_movement.heuristic_value = heuristic_value
                    starting.append( make_movement )

                elif( opend_index > -1 ):
                    copy = starting[ opend_index ]

                    if( final_value < copy.heuristic_value + copy.depth ):
                        copy.heuristic_value = heuristic_value
                        copy.father = make_movement.father
                        copy.depth = make_movement.depth

                elif( closed_index > -1 ):
                    copy = finishing[ closed_index ]

                    if( final_value < copy.heuristic_value + copy.depth ):
                        make_movement.heuristic_value = heuristic_value
                        finishing.make_movement_novamente( copy )
                        starting.append( make_movement )

            finishing.append( x )
            starting = sorted( starting, key = lambda p: p.heuristic_value + p.depth )

        return [], 0

    def shuffle( self, step_count ):
        for i in range( step_count ):
            row, col = self.find( 0 )
            free_space = self.find_valid_moviment()
            target = random.choice( free_space )
            self.change( ( row, col ), target )
            row, col = target

    def find( self, value ):
        if( value < 0 or value > 8 ):
            raise Exception( "value out of range" )

        for row in range( 3 ):
            for col in range( 3 ):
                if( self.adjacent[ row ][ col ] == value ):
                    return row, col

    def peek( self, row, col ):
        return self.adjacent[ row ][ col ]

    def poke( self, row, col, value ):
        self.adjacent[ row ][ col ] = value

    def change( self, pos_a, pos_b ):
        temp = self.peek( *pos_a )
        self.poke( pos_a[ 0 ], pos_a[ 1 ], self.peek( *pos_b ) )
        self.poke( pos_b[ 0 ], pos_b[ 1 ], temp )

def index( item, seq ):
    if item in seq:
        return seq.index( item )

    else:
        return -1

def heuristic( puzzle, total_itens, total_final ):
    t = 0
    for row in range( 3 ):
        for col in range( 3 ):
            val = puzzle.peek( row, col ) - 1
            c_column = val % 3
            c_line = val / 3

            if( c_line < 0 ):
                c_line = 2

            t += total_itens( row, c_line, col, c_column )

    return total_final( t )

def h_manhattan( puzzle ):
    return heuristic( puzzle,
                lambda r, tr, c, tc: abs( tr - r ) + abs( tc - c ),
                lambda t : t )

if __name__ == "__main__":
	main()
