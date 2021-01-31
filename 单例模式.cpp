////解法1.加同步锁前后两次判断实例是否存在
//
//public sealed class Singleton3
//{
//	private Singleton3()
//	{
//
//	}
//	private static object SyncObj = new object();
//	private static Singleton3 instance =null;
//	public static Singletons Instance
//	{
//		get
//		{
//			if (instance == null)
//			{
//				lock(SyncObj);
//				if (instance == null)
//				{
//					instance = new Singleton3();
//				}
//			}
//			return instance;
//		}
//
//	}
//
//}
//
////解法2.利用静态构造函数
//public sealed class Singleton4
//{
//	private Singleton4()
//	{
//
//	}
//
//	private static Singleton4 instance = new Singleton4();
//	public static Singleton4 Instance
//	{
//		get
//		{
//			return instance;
//		}
//		
//	}
//}
//
////解法3.实现按需创建实例
//public sealed class Singleton5
//{
//	Singleton5()
//	{
//
//	}
//	
//	public static Singleton5 Instance
//	{
//		get
//		{
//			return Nested.instance;
//		}
//
//	}
//	class Nested
//	{
//			static Nested()
//			{
//
//			}
//			internal static readonly Singleton5 instance = new Singleton5();
//	}
//}