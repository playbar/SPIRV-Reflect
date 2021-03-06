/// @ref core
/// @file glm/detail/type_mat3x2.hpp

#pragma once

#include "../fwd.hpp"
#include "type_vec2.hpp"
#include "type_vec3.hpp"
#include "type_mat.hpp"
#include <limits>
#include <cstddef>

namespace glm
{
	template<typename T, precision P>
	struct mat<3, 2, T, P>
	{
		typedef vec<2, T, P> col_type;
		typedef vec<3, T, P> row_type;
		typedef mat<3, 2, T, P> type;
		typedef mat<2, 3, T, P> transpose_type;
		typedef T value_type;

	private:
		col_type value[3];

	public:
		// -- Constructors --

		GLM_FUNC_DECL mat() GLM_DEFAULT_CTOR;
		GLM_FUNC_DECL mat(mat<3, 2, T, P> const & m) GLM_DEFAULT;
		template<precision Q>
		GLM_FUNC_DECL mat(mat<3, 2, T, Q> const & m);

		GLM_FUNC_DECL GLM_CONSTEXPR_CTOR explicit mat(ctor);
		GLM_FUNC_DECL explicit mat(T scalar);
		GLM_FUNC_DECL mat(
			T x0, T y0,
			T x1, T y1,
			T x2, T y2);
		GLM_FUNC_DECL mat(
			col_type const & v0,
			col_type const & v1,
			col_type const & v2);

		// -- Conversions --

		template<
			typename X1, typename Y1,
			typename X2, typename Y2,
			typename X3, typename Y3>
		GLM_FUNC_DECL mat(
			X1 x1, Y1 y1,
			X2 x2, Y2 y2,
			X3 x3, Y3 y3);

		template<typename V1, typename V2, typename V3>
		GLM_FUNC_DECL mat(
			vec<2, V1, P> const & v1,
			vec<2, V2, P> const & v2,
			vec<2, V3, P> const & v3);

		// -- Matrix conversions --

		template<typename U, precision Q>
		GLM_FUNC_DECL GLM_EXPLICIT mat(mat<3, 2, U, Q> const & m);

		GLM_FUNC_DECL GLM_EXPLICIT mat(mat<2, 2, T, P> const & x);
		GLM_FUNC_DECL GLM_EXPLICIT mat(mat<3, 3, T, P> const & x);
		GLM_FUNC_DECL GLM_EXPLICIT mat(mat<4, 4, T, P> const & x);
		GLM_FUNC_DECL GLM_EXPLICIT mat(mat<2, 3, T, P> const & x);
		GLM_FUNC_DECL GLM_EXPLICIT mat(mat<2, 4, T, P> const & x);
		GLM_FUNC_DECL GLM_EXPLICIT mat(mat<3, 4, T, P> const & x);
		GLM_FUNC_DECL GLM_EXPLICIT mat(mat<4, 2, T, P> const & x);
		GLM_FUNC_DECL GLM_EXPLICIT mat(mat<4, 3, T, P> const & x);

		// -- Accesses --

		typedef length_t length_type;
		GLM_FUNC_DECL static length_type length(){return 3;}

		GLM_FUNC_DECL col_type & operator[](length_type i);
		GLM_FUNC_DECL col_type const & operator[](length_type i) const;

		// -- Unary arithmetic operators --

		GLM_FUNC_DECL mat<3, 2, T, P> & operator=(mat<3, 2, T, P> const & m) GLM_DEFAULT;

		template<typename U>
		GLM_FUNC_DECL mat<3, 2, T, P> & operator=(mat<3, 2, U, P> const & m);
		template<typename U>
		GLM_FUNC_DECL mat<3, 2, T, P> & operator+=(U s);
		template<typename U>
		GLM_FUNC_DECL mat<3, 2, T, P> & operator+=(mat<3, 2, U, P> const & m);
		template<typename U>
		GLM_FUNC_DECL mat<3, 2, T, P> & operator-=(U s);
		template<typename U>
		GLM_FUNC_DECL mat<3, 2, T, P> & operator-=(mat<3, 2, U, P> const & m);
		template<typename U>
		GLM_FUNC_DECL mat<3, 2, T, P> & operator*=(U s);
		template<typename U>
		GLM_FUNC_DECL mat<3, 2, T, P> & operator/=(U s);

		// -- Increment and decrement operators --

		GLM_FUNC_DECL mat<3, 2, T, P> & operator++ ();
		GLM_FUNC_DECL mat<3, 2, T, P> & operator-- ();
		GLM_FUNC_DECL mat<3, 2, T, P> operator++(int);
		GLM_FUNC_DECL mat<3, 2, T, P> operator--(int);
	};

	// -- Unary operators --

	template<typename T, precision P>
	GLM_FUNC_DECL mat<3, 2, T, P> operator+(mat<3, 2, T, P> const & m);

	template<typename T, precision P>
	GLM_FUNC_DECL mat<3, 2, T, P> operator-(mat<3, 2, T, P> const & m);

	// -- Binary operators --

	template<typename T, precision P>
	GLM_FUNC_DECL mat<3, 2, T, P> operator+(mat<3, 2, T, P> const & m, T scalar);

	template<typename T, precision P>
	GLM_FUNC_DECL mat<3, 2, T, P> operator+(mat<3, 2, T, P> const & m1, mat<3, 2, T, P> const & m2);

	template<typename T, precision P>
	GLM_FUNC_DECL mat<3, 2, T, P> operator-(mat<3, 2, T, P> const & m, T scalar);

	template<typename T, precision P>
	GLM_FUNC_DECL mat<3, 2, T, P> operator-(mat<3, 2, T, P> const & m1, mat<3, 2, T, P> const & m2);

	template<typename T, precision P>
	GLM_FUNC_DECL mat<3, 2, T, P> operator*(mat<3, 2, T, P> const & m, T scalar);

	template<typename T, precision P>
	GLM_FUNC_DECL mat<3, 2, T, P> operator*(T scalar, mat<3, 2, T, P> const & m);

	template<typename T, precision P>
	GLM_FUNC_DECL typename mat<3, 2, T, P>::col_type operator*(mat<3, 2, T, P> const & m, typename mat<3, 2, T, P>::row_type const & v);

	template<typename T, precision P>
	GLM_FUNC_DECL typename mat<3, 2, T, P>::row_type operator*(typename mat<3, 2, T, P>::col_type const & v, mat<3, 2, T, P> const & m);

	template<typename T, precision P>
	GLM_FUNC_DECL mat<2, 2, T, P> operator*(mat<3, 2, T, P> const & m1, mat<2, 3, T, P> const & m2);

	template<typename T, precision P>
	GLM_FUNC_DECL mat<3, 2, T, P> operator*(mat<3, 2, T, P> const & m1, mat<3, 3, T, P> const & m2);

	template<typename T, precision P>
	GLM_FUNC_DECL mat<4, 2, T, P> operator*(mat<3, 2, T, P> const & m1, mat<4, 3, T, P> const & m2);

	template<typename T, precision P>
	GLM_FUNC_DECL mat<3, 2, T, P> operator/(mat<3, 2, T, P> const & m, T scalar);

	template<typename T, precision P>
	GLM_FUNC_DECL mat<3, 2, T, P> operator/(T scalar, mat<3, 2, T, P> const & m);

	// -- Boolean operators --

	template<typename T, precision P>
	GLM_FUNC_DECL bool operator==(mat<3, 2, T, P> const & m1, mat<3, 2, T, P> const & m2);

	template<typename T, precision P>
	GLM_FUNC_DECL bool operator!=(mat<3, 2, T, P> const & m1, mat<3, 2, T, P> const & m2);

}//namespace glm

#ifndef GLM_EXTERNAL_TEMPLATE
#include "type_mat3x2.inl"
#endif
