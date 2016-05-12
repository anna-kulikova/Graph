#include "gtest.h"
#include "Table.h"
#include "Tab_Record.h"
#include "Scan_Table.h"
#include "Sort_Table.h"
#include "Hash_Table.h"
#include "Array_Hash_Table.h"


TEST(TABRECORD, can_create_table)
{
	TabRecord *tab;
	ASSERT_NO_THROW(tab = new TabRecord(3, "abc"));
}

TEST(TABRECORD, can_get_key)
{
	TabRecord *tab = new TabRecord(3, "abc");
	int k;
	ASSERT_NO_THROW(k = tab->GetKey());
}

TEST(TABRECORD, can_get_data)
{
	TabRecord *tab = new TabRecord(3, "abc");
	char *d;
	ASSERT_NO_THROW(d = tab->GetData());
}

TEST(TABRECORD, get_key_correctly)
{
	TabRecord *tab = new TabRecord(3, "abc");
	int k = tab->GetKey();
	EXPECT_EQ(3, k);
}

TEST(TABRECORD, get_data_correctly)
{
	TabRecord *tab = new TabRecord(3, "abc");
	char *d = tab->GetData();
	EXPECT_EQ("abc", d);
}

TEST(SCANTABLE, can_create_table_by_size)
{
	ASSERT_NO_THROW(ScanTable *tab = new ScanTable(2));
}

TEST(SCANTABLE, can_create_table)
{
	ASSERT_NO_THROW(ScanTable *tab = new ScanTable());
}

TEST(SCANTABLE, can_copy_table)
{
	ScanTable s(2);
	ASSERT_NO_THROW(ScanTable cps(s));
}

TEST(SCANTABLE, can_search)
{
	ScanTable *s = new ScanTable();
	s->Push(1, "a");
	s->Push(5, "b");
	TabRecord* t;
	ASSERT_NO_THROW(t = s->Search(5));
}

TEST(SCANTABLE, can_push)
{
	ScanTable s(2);
	ASSERT_NO_THROW(s.Push(3, "abc"));
}

TEST(SCANTABLE, can_remove)
{
	ScanTable *s = new ScanTable();
	s->Push(1, "a");
	s->Push(5, "b");
	ASSERT_NO_THROW(s->Remove(1));
}

TEST(SORTTABLE, can_create_table)
{
	ASSERT_NO_THROW(SortTable *s = new SortTable(2));
}

TEST(SORTTABLE, can_copy_table)
{
	SortTable s(2);
	ASSERT_NO_THROW(SortTable cps(s));
}

TEST(SORTTABLE, can_search)
{
	SortTable *s = new SortTable(1);
	s->Push(1, "a");
	s->Push(5, "b");
	TabRecord* t;
	ASSERT_NO_THROW(t = s->Search(5));
}

TEST(SORTTABLE, can_push)
{
	SortTable s(2);
	ASSERT_NO_THROW(s.Push(3, "abc"));
}

TEST(SORTTABLE, can_remove)
{
	SortTable *s = new SortTable(2);
	s->Push(1, "a");
	s->Push(5, "b");
	ASSERT_NO_THROW(s->Remove(1));
}

TEST(SORTTABLE, can_sort)
{
	SortTable s(2);
	ASSERT_NO_THROW(s.SortData());
}


//TEST(SCANTABLE, searches_correctly)
//{
//	ScanTable s(3);
//	s.Push(1, "a");
//	s.Push(2, "b");
//	s.Push(3, "c");
//	TabRecord expData(2, "b");
//	EXPECT_EQ(expData->GetData(), s.Search(2)->GetData());
//}



TEST(SCANTABLE, can_get_count)
{
	ScanTable s(3);
	ASSERT_NO_THROW(s.GetCount());
}

TEST(SCANTABLE, cant_create_table_with_invalid_argument)
{
	ASSERT_ANY_THROW(ScanTable s(-1));
}

TEST(SCANTABLE, insert_increases_count)
{
	ScanTable s(3);
	size_t expCount = s.GetCount() + 1;
	s.Push(1, "b");
	s.Push(2, "a");
	cout << expCount << " " << s.GetCount();
	EXPECT_EQ(expCount, s.GetCount());
}

TEST(SCANTABLE, cant_insert_record_when_table_is_full)
{
	ScanTable s(3);
	s.Push(1, "a");
	s.Push(2, "b");
	s.Push(3, "c");
	ASSERT_ANY_THROW(s.Push(4, "d"));
}

TEST(SCANTABLE, removing_decrease_count)
{
	ScanTable s(3);
	s.Push(1, "a");
	s.Push(2, "b");
	s.Push(3, "c");
	size_t expCount = s.GetCount() - 1;
	s.Remove(1);
	EXPECT_EQ(expCount, s.GetCount());
}

TEST(SCANTABLE, cant_remove_record_when_table_is_empty)
{
	ScanTable s(3);
	ASSERT_ANY_THROW(s.Remove(1));
}

TEST(SCANTABLE, removing_of_non_existing_record_does_not_decrease_count)
{
	ScanTable s(3);
	s.Push(1, "a");
	s.Push(2, "b");
	s.Push(3, "c");
	size_t expCount = s.GetCount();
	s.Remove(4);
	EXPECT_EQ(expCount, s.GetCount());
}

TEST(SCANTABLE, search_does_not_change_count)
{
	ScanTable s(3);
	s.Push(1, "a");
	s.Push(2, "b");
	s.Push(3, "c");
	size_t expCount = s.GetCount();
	s.Search(2);
	EXPECT_EQ(expCount, s.GetCount());
}

TEST(SCAN_TABLE, search_returns_0_if_record_does_not_exist)
{
	ScanTable s(3);
	s.Push(1, "a");
	s.Push(2, "b");
	s.Push(3, "c");
	EXPECT_EQ(NULL, s.Search(4));
}

TEST(SCANTABLE, copied_table_is_equal_to_source_one)
{
	ScanTable s(3);
	s.Push(1, "a");
	s.Push(2, "b");
	s.Push(3, "c");
	ScanTable copyt(s);
	EXPECT_EQ(s.GetCount(), copyt.GetCount());
}

TEST(ARRAYHASHTABLE, can_create_table)
{
	ASSERT_NO_THROW(Table *ht = new ArrayHashTable(5, 2));
}

TEST(ARRAYHASHTABLE, can_search)
{
	ArrayHashTable *ht = new ArrayHashTable(5, 2);
	ht->Push(1, "b");
	ASSERT_NO_THROW(ht->Search(1));
}

TEST(ARRAYHASHTABLE, can_push)
{
	ArrayHashTable *ht = new ArrayHashTable(5, 2);
	ASSERT_NO_THROW(ht->Push(1, "b"));
}

TEST(ARRAYHASHTABLE, can_remove)
{
	ArrayHashTable *ht = new ArrayHashTable(5, 2);
	ht->Push(1, "b");
	ASSERT_NO_THROW(ht->Remove(1));
}

TEST(ARRAYHASHTABLE, can_reset)
{
	ArrayHashTable *ht = new ArrayHashTable(5, 2);
	ht->Push(1, "b");
	ASSERT_NO_THROW(ht->Reset());
}

TEST(ARRAYHASHTABLE, can_get_next)
{
	ArrayHashTable *ht = new ArrayHashTable(5, 2);
	ht->Push(1, "b");
	ASSERT_NO_THROW(ht->GetNext());
}

TEST(ARRAYHASHTABLE, insert_increases_count)
{
	ArrayHashTable ht(3, 1);
	size_t expCount = ht.GetCount() + 1;
	ht.Push(1, "b");
	EXPECT_EQ(expCount, ht.GetCount());
}

TEST(ARRAYHASHTABLE, remove_decreases_count)
{
	ArrayHashTable ht(3, 1);
	ht.Push(1, "a");
	ht.Push(2, "b");
	ht.Push(3, "c");
	size_t expCount = ht.GetCount() - 1;
	ht.Remove(1);
	EXPECT_EQ(expCount, ht.GetCount());
}


