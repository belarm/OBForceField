BEGIN {file = 0; filename = "model_" file ".pdb"}
/ENDMDL/ {getline; file ++; filename = "model_" file ".pdb"}
{print $0 > filename}
