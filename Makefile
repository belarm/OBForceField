.PHONY: clean All

All:
	@echo "----------Building project:[ BuildMol - Debug ]----------"
	@cd "BuildMol" && "$(MAKE)" -f  "BuildMol.mk"
clean:
	@echo "----------Cleaning project:[ BuildMol - Debug ]----------"
	@cd "BuildMol" && "$(MAKE)" -f  "BuildMol.mk" clean
