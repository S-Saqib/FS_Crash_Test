DB_USER="root"
DB_PASSWORD="root123"
DB_NAME="fs_db"
SQL_FILE="one_record_inserter.sql"

# Execute the query using the mysql command
mysql -u"$DB_USER" -p"$DB_PASSWORD" "$DB_NAME" < "$SQL_FILE"
