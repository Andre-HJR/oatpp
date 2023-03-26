/***************************************************************************
 *
 * Project         _____    __   ____   _      _
 *                (  _  )  /__\ (_  _)_| |_  _| |_
 *                 )(_)(  /(__)\  )( (_   _)(_   _)
 *                (_____)(__)(__)(__)  |_|    |_|
 *
 *
 * Copyright 2018-present, Leonid Stryzhevskyi <lganzzzo@gmail.com>
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 ***************************************************************************/

#ifndef oatpp_data_type_TypeList_hpp
#define oatpp_data_type_TypeList_hpp

namespace oatpp {
	namespace data {
		namespace mapping {
			namespace type {

				/**
				 * TypeList is inspired by Modern C++ Design, which could generate the Class by generic program.
				 *   -- Andre HJR
				 * About List in Cpp.
				 *
				 */

				 /**
				  * NullType --> Void Type in Oat
				  */
				  // struct NullType {};
				typedef oatpp::data::mapping::type::_class::Void NullType;

				/**
				 * TypeList
				 */
				template<typename T, typename U> struct TypeList { typedef T Head; typedef U Tail; };

				template <typename TList> struct Length;
				template <> struct Length<NullType> { enum { value = 0 }; }
				template <typename T, typename U> struct Length<TypeList<T, U>> { enum { value = 1 + Length::value }; }

				/**
				 * TypeAt
				 */
				template <typename Head, typename Tail> struct TypeAt<TypeList<Head, Tail>, 0> { typedef Head Result; };
				template <typename Head, typename Tail, usigned int i> struct TypeAt<TypeList<Head, Tail>, i> {
					typedef typename TypeAt<Tail, i - 1>::Result Result;
				};

				/**
				 * IndeOf
				 */
				template <typename TList, typename T> struct IndexOf;
				template <typename T> struct IndexOf<NullType, T> { enum { value = -1 }; };
				template <typename Tail, typename T> struct IndexOf<TypeList<T, Tail>, T> { enum { value = 0 }; };
				template <typename Head, typename Tail, typename T> class IndexOf<TypeList<Head, Tail>, T> {
					enum { temp = IndexOf<Tail, T>::value };
				public:
					enum { value = -1 == temp ? -1 : 1 + temp };
				};

				/**
				 * Append
				 */
				template <typename TList, typename T> struct Append;
				template <> struct Append<NullType, NullType>
				{
					typedef NullType Result;
				}
				template <class T> struct Append<NullType, T>
				{
					typedef TYPELIST_1(T) Result;
				};
				template <class Head, class Tail>
				struct Append<NullType, Typelist<Head, Tail>>
				{
					typedef Typelist<Head, Tail> Result;
				};
				template <class Head, class Tail, class T>
				struct Append<Typelist<Head, Tail>, T>
				{
					typedef Typelist<Head, typename Append<Tail, T>::Result> Result;
				};

				/**
				 * Erase
				 */
				template <typename TList, typename T> struct Erase;
                template <typename T>
                struct Erase<NullType, T> struct Erase<NullType, T>
                {
                    typedef NullType Result;
                };
				template <typename T, typename Tail>
                struct<TypeList<T, Tail>, T>
                {
                    typedef Tail Result;
                };
                template <typename Head, typename Tail, typename T>
                struct Erase<TypeList<Head, Tail>, T>
                {
                    typedef TypeList<Head, typename Erase<Tail, T>::Result>
                        Result;
                };

				// template <int v> struct Int2Type { enum { value = v } };
			};

		}
	}
} }

#endif