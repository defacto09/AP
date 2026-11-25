import unittest
from Lab_07_1_rec import (count_criterion, sum_criterion, replace_criterion_with_zero,
                          need_swap, sort_rows, init_matrix)


class TestLab071Rec(unittest.TestCase):
    def setUp(self):
        self.a = [[-5, 4, -8, -17, 0],
                  [3, -12, -1, 14, -2]]

    def test_count(self):
        self.assertEqual(count_criterion(self.a, 0), 4)   # -5, -17, -1, -2

    def test_sum(self):
        self.assertEqual(sum_criterion(self.a, 0), -25)

    def test_replace(self):
        replace_criterion_with_zero(self.a, 0)
        self.assertEqual(self.a, [[0, 4, -8, 0, 0],
                                  [3, -12, 0, 14, 0]])

    def test_need_swap(self):
        self.assertTrue(need_swap([2, 0, 0], [1, 9, 9], 0))    # 1-й стовпчик
        self.assertTrue(need_swap([1, 5, 0], [1, 2, 9], 0))    # 2-й стовпчик
        self.assertTrue(need_swap([1, 2, 9], [1, 2, 4], 0))    # 3-й стовпчик
        self.assertFalse(need_swap([1, 2, 4], [1, 2, 4], 0))   # однакові

    def test_sort_three_keys(self):
        a = [[2, 1, 5, 0, 0],
             [1, 7, 3, 0, 0],
             [1, 2, 9, 0, 0],
             [1, 2, 4, 0, 0]]
        sort_rows(a, 0)
        self.assertEqual(a, [[1, 2, 4, 0, 0],
                             [1, 2, 9, 0, 0],
                             [1, 7, 3, 0, 0],
                             [2, 1, 5, 0, 0]])

    def test_init_size_and_range(self):
        a = init_matrix(8, 5, -17, 14)
        self.assertEqual(len(a), 8)
        for row in a:
            self.assertEqual(len(row), 5)
            for x in row:
                self.assertTrue(-17 <= x <= 14)


if __name__ == "__main__":
    unittest.main()
