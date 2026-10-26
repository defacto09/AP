import unittest
from Lab_06_1 import create_array, count_elements, sum_element, zeroing


class TestLab06_1(unittest.TestCase):
    def setUp(self):
        # фіксований масив, для якого відповіді пораховано вручну
        self.t = [8, 5, 2, 1, -11, -9, -6, 2, 5, 4, 4, -6, 13,
                  -6, -3, 13, 10, 8, 13, -1, 5, 9, 8, -4, 0]

    def test_count(self):
        self.assertEqual(count_elements(self.t), 7)

    def test_sum(self):
        self.assertEqual(sum_element(self.t), -40)

    def test_zeroing(self):
        zeroing(self.t)
        self.assertEqual(self.t, [8, 5, 2, 1, 0, 0, -6, 2, 5, 4, 4, 0, 13,
                                  0, 0, 13, 10, 8, 13, 0, 5, 9, 8, 0, 0])

    def test_create_array(self):
        t = create_array(-11, 13, 25)
        self.assertEqual(len(t), 25)
        for x in t:
            self.assertTrue(-11 <= x <= 13)


if __name__ == "__main__":
    unittest.main()