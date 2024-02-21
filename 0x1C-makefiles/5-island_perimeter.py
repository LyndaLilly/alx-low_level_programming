#!/usr/bin/python3
"""the function maps out the size of the island"""


def island_perimeter(grid):
    """this output perimeter of the island.
    grid displays water by 0 and land by 1.
    Args:
        grid (list): sums the list of values displayng the island.
    Returns:
        The side of the island outlined in grid.
    """
    w = len(grid[0])
    h = len(grid)
    e = 0
    s = 0

    for x in range(h):
        for y in range(w):
            if grid[x][y] == 1:
                s += 1
                if (y > 0 and grid[x][y - 1] == 1):
                    e += 1
                if (x > 0 and grid[x - 1][y] == 1):
                    e += 1
    return s * 4 - e * 2
