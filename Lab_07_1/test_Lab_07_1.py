import unittest
from Lab_07_1 import (is_criterion, count_criterion, sum_criterion,
                      replace_criterion_with_zero, sort_rows, init_matrix)
 
 
class TestLab071(unittest.TestCase):
    def setUp(self):
        self.a = [[-5, 4, -8, -17, 0],
                  [3, -12, -1, 14, -2]]
 
    def test_is_criterion(self):
        self.assertTrue(is_criterion(-5))
        self.assertFalse(is_criterion(-8))   # кратне 4
        self.assertFalse(is_criterion(0))
        self.assertFalse(is_criterion(3))
 
    def test_count(self):
        self.assertEqual(count_criterion(self.a), 4)   # -5, -17, -1, -2
 
    def test_sum(self):
        self.assertEqual(sum_criterion(self.a), -25)
 
    def test_replace(self):
        replace_criterion_with_zero(self.a)
        self.assertEqual(self.a, [[0, 4, -8, 0, 0],
                                  [3, -12, 0, 14, 0]])
 
    def test_sort_three_keys(self):
        a = [[2, 1, 5, 0, 0],
             [1, 7, 3, 0, 0],
             [1, 2, 9, 0, 0],
             [1, 2, 4, 0, 0]]
        sort_rows(a)
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
 