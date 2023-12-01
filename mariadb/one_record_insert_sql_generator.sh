SQL_FILE="one_record_inserter.sql"
K_VALUE="K_F"
V_VALUE=""
vSizeInBytes=1500000;

for ((i = 0; i < vSizeInBytes; i++)); do
    V_VALUE+="1"
done

# SQL query
SQL_QUERY="INSERT INTO testkv (k, v) VALUES ('$K_VALUE', '$V_VALUE');"

echo $SQL_QUERY > $SQL_FILE
