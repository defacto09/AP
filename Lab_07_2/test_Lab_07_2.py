import unittest
from Lab_07_2 import sum_main_diagonal


class TestSumMainDiagonal(unittest.TestCase):
    def test_3x3(self):
        a = [[9, 10, -2], [6, -4, -9], [9, 0, 9]]
        self.assertEqual(sum_main_diagonal(a), 14)

    def test_from_screenshot(self):
        a = [[1, 9, 9], [1, -9, -7], [-10, -8, 3]]
        self.assertEqual(sum_main_diagonal(a), -5)

    def test_1x1(self):
        self.assertEqual(sum_main_diagonal([[7]]), 7)

    def test_only_diagonal_counts(self):
        a = [[1, 100], [100, 2]]
        self.assertEqual(sum_main_diagonal(a), 3)


if __name__ == "__main__":
    unittest.main()