#include <gtest.h>
#include "Table.h"
#include "scan_table.h"
#include "sort_table.h"
#include "tab_record.h"

TEST(Table, can_create_Table)
{
	ASSERT_NO_THROW(ScanTable *a = new ScanTable(5));
}

TEST(Table, created_Table_is_empty)
{
	ScanTable *a = new ScanTable(5);
	EXPECT_EQ(1, a->IsEmpty());
}

TEST(Table, can_Push_record_to_Table)
{
	ScanTable *a = new ScanTable(5);
	ASSERT_NO_THROW(a->Push(1, 2));
}

TEST(Table, can_Remove_record_from_Table)
{
	ScanTable *a = new ScanTable(5);
	a->Push(1, 2);
	ASSERT_NO_THROW(a->Remove(1));
}

TEST(Table, can_Remove_record_from_Table2)
{
	ScanTable *a = new ScanTable(5);
	a->Push(1, 2);
	EXPECT_EQ(a->IsEmpty(), 0);
}



TEST(Table, can_find_record)
{
	ScanTable *a = new ScanTable(5);
	a->Push(1, 2);
	a->Push(2, 3);
	a->Push(3, 4);
	EXPECT_EQ(a->FindKey(2)->GetData(), 3);
}

TEST(Table, throws_when_push_to_full_table)
{
	ScanTable *a = new ScanTable(5);
	a->Push(1, 2);
	a->Push(2, 3);
	a->Push(3, 4);
	a->Push(4, 5);
	a->Push(5, 6);
	ASSERT_ANY_THROW(a->Push(6, 7));
}

TEST(Table, can_check_fullness)
{
	ScanTable *a = new ScanTable(5);
	a->Push(1, 2);
	a->Push(2, 3);
	a->Push(3, 4);
	a->Push(4, 5);
	a->Push(5, 6);
	EXPECT_EQ(a->IsFull(), 1);
}

TEST(Table, can_get_count)
{
	ScanTable *a = new ScanTable(5);
	a->Push(1, 2);
	a->Push(2, 3);
	a->Push(3, 4);
	a->Push(4, 5);
	EXPECT_EQ(a->GetCount(), 4);
}

TEST(Table, throws_when_GoNext_in_full_table)
{
	ScanTable *a = new ScanTable(5);
	a->Push(1, 2);
	a->Push(2, 3);
	a->Push(3, 4);
	a->Push(4, 5);
	a->Push(5, 6);
	EXPECT_EQ(a->GoNext(), 1);
}

TEST(Table, can_create_sorttable)
{
	ASSERT_NO_THROW(SortTable *a = new SortTable(5));
}

TEST(Table, can_copy_scantable_to_sorttable)
{
	ScanTable *a = new ScanTable(5);
	ASSERT_NO_THROW(SortTable *b = new SortTable(*a));
}

TEST(Table, can_FindKey_in_sorttable)
{
	SortTable *a = new SortTable(5);
	a->Push(1, 2);
	a->Push(2, 3);
	a->Push(3, 4);
	a->Push(4, 5);
	a->Push(5, 6);
	EXPECT_EQ(a->FindKey(3)->GetData(), 4);
}

TEST(Table, can_Remove_in_sorttable)
{
	SortTable *a = new SortTable(5);
	a->Push(1, 2);
	a->Push(2, 3);
	a->Push(3, 4);
	a->Push(4, 5);
	a->Push(5, 6);
	ASSERT_NO_THROW(a->Remove(3));
}

TEST(Table, can_sort_table)
{
	SortTable *a = new SortTable(5);
	a->Push(1, 2);
	a->Push(2, 3);
	a->Push(3, 4);
	a->Push(4, 5);
	a->Push(5, 6);
	ASSERT_NO_THROW(a->Sort());
}

TEST(Table, can_getmin)
{
	SortTable *a = new SortTable(5);
	a->Push(1, 2);
	a->Push(2, 3);
	a->Push(3, 4);
	a->Push(4, 5);
	a->Push(5, 6);
	EXPECT_EQ(a->Min()->GetData(), 2);
}
