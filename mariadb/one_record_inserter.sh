DB_USER="root"
DB_PASSWORD="root123"
DB_NAME="fs_db"

# Values to insert
K_VALUE="k2"
V_VALUE="v2"

# SQL query
SQL_QUERY="INSERT INTO testkv (k, v) VALUES ('$K_VALUE', '$V_VALUE');"

# Execute the query using the mysql command
mysql -u"$DB_USER" -p"$DB_PASSWORD" "$DB_NAME" -e "$SQL_QUERY"
