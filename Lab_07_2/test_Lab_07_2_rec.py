import unittest
from Lab_07_2_rec import sum_main_diagonal, init_matrix


class TestLab0702Rec(unittest.TestCase):
    def test_sum_3x3(self):
        a = [[9, 10, -2], [6, -4, -9], [9, 0, 9]]
        self.assertEqual(sum_main_diagonal(a, 0), 14)

    def test_sum_from_run(self):
        a = [[4, 0, 2], [-7, -5, 6], [-3, -1, -10]]
        self.assertEqual(sum_main_diagonal(a, 0), -11)

    def test_sum_only_diagonal(self):
        a = [[1, 100], [100, 2]]
        self.assertEqual(sum_main_diagonal(a, 0), 3)

    def test_init_matrix_size_and_range(self):
        m = init_matrix(4, 4, -10, 10)
        self.assertEqual(len(m), 4)
        for row in m:
            self.assertEqual(len(row), 4)
            for x in row:
                self.assertTrue(-10 <= x <= 10)


if __name__ == "__main__":
    unittest.main()