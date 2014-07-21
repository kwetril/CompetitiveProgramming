main = do
	str <- getLine
	putStrLn $ solve str

solve :: String -> String
solve s = foldl f "" s

f :: String -> Char -> String
f a b = if elem b a
	then a 
	else a++[b]
