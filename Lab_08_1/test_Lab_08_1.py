import unittest
from Lab_08_1 import scan_comma_dash, qty_comma_dash, replace_comma_dash


class TestLab081(unittest.TestCase):
    def test_has(self):
        self.assertTrue(scan_comma_dash("a,-b"))
        self.assertFalse(scan_comma_dash("a-,b, -c"))  # "-," не пара
        self.assertFalse(scan_comma_dash(""))

    def test_count(self):
        self.assertEqual(qty_comma_dash("x,-y,-z"), 2)
        self.assertEqual(qty_comma_dash(",-,-,-"), 3)
        self.assertEqual(qty_comma_dash(",,--"), 1)  # одна пара
        self.assertEqual(qty_comma_dash("abc"), 0)

    def test_replace(self):
        self.assertEqual(replace_comma_dash("x,-y,-z"), "x*y*z")
        self.assertEqual(replace_comma_dash(",-,-"), "**")
        self.assertEqual(replace_comma_dash(",,--"), ",*-")
        self.assertEqual(replace_comma_dash("a,b-c"), "a,b-c")  # без пар
        self.assertEqual(replace_comma_dash(","), ",")  # кома в кінці


if __name__ == "__main__":
    unittest.main()
