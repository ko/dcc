SCANNER_X=scanner.x
SCANNER_HS=scanner.hs
SCANNER_HS_BIN=scanner scanner.hi scanner.o

scan:
	alex $(SCANNER_X) -o $(SCANNER_HS)
	ghc $(SCANNER_HS)

scan-clean:
	rm -f $(SCANNER_HS)
	rm -f $(SCANNER_HS_BIN)

clean: \
	scan-clean


