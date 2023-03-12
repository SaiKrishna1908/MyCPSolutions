from collections import deque

op_map = {'+': 1, '-': 1, '*': 1, '/': 1, 'O': 0}

def print_vec(arr):
    for val in arr:
        print(val, end=" ")
    print()

def run():
    n = int(input())

    nodes = {}
    for i in range(n):
        id, predc, succ, op = input().split()
        id, predc, succ = map(int, [id, predc, succ])

        preds = [int(x) for x in input().split()]
        succs = [int(x) for x in input().split()]

        node = (preds, succs, op)
        nodes[id] = node

    dq = deque([(1, 1)])
    max_time = 0
    result = {}

    while dq:
        current_node_id, current_cost = dq.popleft()
        current_node = nodes[current_node_id]
        current_cost += op_map[current_node[2]]
        max_time = max(max_time, current_cost)

        result[current_node_id] = max(result.get(current_node_id, 0), max_time)
        for neighbour_id in current_node[1]:
            dq.append((neighbour_id, max_time))

    print("Node, Time")
    for node_id in sorted(result):
        print(f"{node_id} {result[node_id]}")

if __name__ == '__main__':
    run()