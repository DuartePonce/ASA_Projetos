from pulp import *

# data as a dictionary
items = {
    'item1': {'weight': 4, 'price': 19},
    'item2': {'weight': 2, 'price': 17},
    'item3': {'weight': 8, 'price': 30},
    'item4': {'weight': 3, 'price': 13},
    'item5': {'weight': 7, 'price': 25},
    'item6': {'weight': 5, 'price': 29},
    'item7': {'weight': 9, 'price': 23},
    'item8': {'weight': 6, 'price': 10}
}

carry_weight = 17

# problem formulation
model = LpProblem(sense=LpMaximize)

variables = {item: LpVariable(name=f"x_{item}", cat=LpBinary) for item in items}

model += lpSum(items[item]['weight'] * variables[item] for item in items) <= carry_weight

model += lpSum(items[item]['price'] * variables[item] for item in items)

# solve (without being verbose)
status = model.solve(PULP_CBC_CMD(msg=False))
print("price:", model.objective.value())
print("take:", {item: variables[item].value() for item in items})
