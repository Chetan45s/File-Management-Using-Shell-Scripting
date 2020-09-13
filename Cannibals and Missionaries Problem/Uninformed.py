def check_goal(cl,ml):
    if cl == 0 and ml == 0:
        return True
    else:
        return False
    
def is_safe(cl,ml,cr,mr):
    if cl >= 0 and ml >= 0 and cr >= 0 and mr >= 0 and (ml == 0 or ml >= cl) and (mr == 0 or mr >= cr):
        return True
    else:
        return False

class Node():
    def __init__(self,cl,ml,side,cr,mr):
        self.cl = cl
        self.cr = cr
        self.ml = ml
        self.mr = mr
        self.side = side
        self.parent_node = None

def create_node(current_node):
    child_nodes = []
    if current_node.side == 'left':
        new_node = Node(current_node.cl,current_node.ml - 2, 'right', current_node.cr, current_node.mr + 2)
        if is_safe(new_node.cl, new_node.ml, new_node.cr,new_node.mr):
            new_node.parent_node = current_node
            child_nodes.append(new_node)

        new_node = Node(current_node.cl - 2,current_node.ml, 'right', current_node.cr + 2, current_node.mr)
        if is_safe(new_node.cl, new_node.ml, new_node.cr,new_node.mr):
            new_node.parent_node = current_node
            child_nodes.append(new_node)

        new_node = Node(current_node.cl - 1,current_node.ml - 1, 'right', current_node.cr + 1, current_node.mr + 1)
        if is_safe(new_node.cl, new_node.ml, new_node.cr,new_node.mr):
            new_node.parent_node = current_node
            child_nodes.append(new_node)
        
        new_node = Node(current_node.cl,current_node.ml - 1, 'right', current_node.cr, current_node.mr + 1)
        if is_safe(new_node.cl, new_node.ml, new_node.cr,new_node.mr):
            new_node.parent_node = current_node
            child_nodes.append(new_node)

        new_node = Node(current_node.cl - 1,current_node.ml, 'right', current_node.cr + 1, current_node.mr)
        if is_safe(new_node.cl, new_node.ml, new_node.cr,new_node.mr):
            new_node.parent_node = current_node
            child_nodes.append(new_node)
        
    else:
        new_node = Node(current_node.cl,current_node.ml + 2, 'left', current_node.cr, current_node.mr - 2)
        if is_safe(new_node.cl, new_node.ml, new_node.cr,new_node.mr):
            new_node.parent_node = current_node
            child_nodes.append(new_node)

        new_node = Node(current_node.cl + 2,current_node.ml, 'left', current_node.cr - 2, current_node.mr)
        if is_safe(new_node.cl, new_node.ml, new_node.cr,new_node.mr):
            new_node.parent_node = current_node
            child_nodes.append(new_node)

        new_node = Node(current_node.cl + 1,current_node.ml + 1, 'left', current_node.cr - 1, current_node.mr - 1)
        if is_safe(new_node.cl, new_node.ml, new_node.cr,new_node.mr):
            new_node.parent_node = current_node
            child_nodes.append(new_node)
        
        new_node = Node(current_node.cl,current_node.ml + 1, 'left', current_node.cr, current_node.mr - 1)
        if is_safe(new_node.cl, new_node.ml, new_node.cr,new_node.mr):
            new_node.parent_node = current_node
            child_nodes.append(new_node)

        new_node = Node(current_node.cl + 1,current_node.ml, 'left', current_node.cr - 1, current_node.mr)
        if is_safe(new_node.cl, new_node.ml, new_node.cr,new_node.mr):
            new_node.parent_node = current_node
            child_nodes.append(new_node)       

    return child_nodes

def bfs():
    people = int(input("Enter the total Number of People : "))
    people = people/2
    start = Node(people,people,'left',0,0)
    if check_goal(start.ml,start.cl):
        return start
    fo = list()
    ex = set()
    fo.append(start)
    while fo:
        create_node1 = fo.pop(0)
        if check_goal(create_node1.ml,create_node1.cl):
            return create_node1
        ex.add(create_node1)
        node = create_node(create_node1)
        for n in node:
            if (n not in ex) or (n not in fo):
                fo.append(n)
    return None


def print_solution(solution):
    path = []
    path.append(solution)
    parent_node = solution.parent_node
    while parent_node:
        path.append(parent_node)
        parent_node = parent_node.parent_node
    print("+------------------------------------------------------------------------------------------")
    print("| Left Cannibal  |  Left Cannibal  |    Boat    |  Right Cannibal  |  Right Missionary    |")
    print("+------------------------------------------------------------------------------------------")
    for states in range(len(path)):
        state = path[len(path) - states - 1]
        if(state.side == 'left'):
            print("|       " + str(state.cl) + "        |        " + str(state.ml) + "        |  " + str(state.side) + "      |        " + str(state.cr) + "         |        " + str(state.mr) + "          |")
        else:
            print("|       " + str(state.cl) + "        |        " + str(state.ml) + "        |  " + str(state.side) + "     |        " + str(state.cr) + "         |        " + str(state.mr) + "          |")
    print("+------------------------------------------------------------------------------------------")
    print("Total Number of steps in which all Cannibal and Missionary moved to side of the river : ",len(path)-1)


def main():
    solution = bfs()
    print_solution(solution)

# if called from the command line, call main()
if __name__ == "__main__":
    main()