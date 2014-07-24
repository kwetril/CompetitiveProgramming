main = do
	str <- getLine
	putStrLn $ show $ (\ [n,m] -> solve (n*m)) $ map (\ x -> read x::Int)  $ words str

solve :: Int -> Double
solve 1 = 1
solve n = 1 + x/(x-1) * solve (n-1)
	where x = fromIntegral n
