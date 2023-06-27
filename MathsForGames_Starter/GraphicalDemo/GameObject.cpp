#include "GameObject.h"

namespace aie
{
	void GameObject::OnUpdate(float deltaTime)
	{
		// left intentionally blank
	}

	void GameObject::OnDraw()
	{
		// left intentionally blank
	}

	GameObject::GameObject()
	{
		Parent = nullptr;

		// IMPORTANT: Set LocalPosition.Z to 1 if translation should be inherited
		LocalPosition = Vector3(0, 0, 1);
		LocalRotation = 0;
		LocalScale = Vector3(1, 1, 1);

	}

	void GameObject::SetParent(GameObject* newParent)
	{
		// remove from existing parent if any
		if (Parent != nullptr)
		{
			// returns an iterator to this child in its parent's vector of children
			auto findIt = std::find(Parent->Children.begin(), Parent->Children.end(), this);

			// if found, iterator will be something besides the end of the vector
			if (findIt != Parent->Children.end())
			{
				Parent->Children.erase(findIt);
				Parent = nullptr;
			}
		}

		// add to new parent if any
		if (newParent != nullptr)
		{
			Parent = newParent;
			Parent->Children.push_back(this);
		}
	}

	GameObject* GameObject::GetParent()
	{
		return Parent;
	}

	const GameObject* GameObject::GetParent() const
	{
		return Parent;
	}

	GameObject* GameObject::GetChild(size_t childIndex)
	{
		return Children[childIndex];
	}

	const GameObject* GameObject::GetChild(size_t childIndex) const
	{
		return Children[childIndex];
	}

	Vector3 GameObject::GetLocalPosition() const
	{
		return LocalPosition;
	}

	void GameObject::SetLocalPosition(Vector3 newPosition)
	{
		LocalPosition = newPosition;
	}

	void GameObject::SetLocalPosition(float newX, float newY)
	{
		LocalPosition = Vector3(newX, newY, LocalPosition.z);
	}

	Vector3 GameObject::GetWorldPosition() const
	{
		Matrix3 worldMat = GetWorldMatrix();
		return Vector3(worldMat.m7, worldMat.m8, worldMat.m9);
	}

	float GameObject::GetLocalRotation() const
	{
		return LocalRotation;
	}

	void GameObject::SetLocalRotation(float newRotation)
	{
		LocalRotation = newRotation;
	}

	float GameObject::GetWorldRotation() const
	{
		Vector3 fwd = GetForward();
		return AngleFrom2D(fwd.x, fwd.y);
	}

	Vector3 GameObject::GetLocalScale() const
	{
		return LocalScale;
	}

	void GameObject::SetLocalScale(Vector3 newScale)
	{
		LocalScale = newScale;
	}

	void GameObject::SetLocalScale(float newX, float newY)
	{
		LocalScale = Vector3(newX, newY, LocalScale.z);
	}

	Vector3 GameObject::GetWorldScale() const
	{
		// calculate the local transform matrix
		Matrix3 myTransform = GetWorldMatrix();

		return Vector3(Vector3(myTransform.m1, myTransform.m2, 0).Magnitude(),
					   Vector3(myTransform.m4, myTransform.m5, 0).Magnitude(),
			           1.0f);
	}

	Vector3 GameObject::GetForward() const
	{
		auto mat = GetWorldMatrix();
		return Vector3(mat[0], mat[1], mat[2]);
	}

	Matrix3 GameObject::GetLocalMatrix() const
	{
		return
			Matrix3::MakeTranslation(LocalPosition) *
			Matrix3::MakeRotateZ(LocalRotation) *
			Matrix3::MakeScale(LocalScale.x, LocalScale.y);
	}

	Matrix3 GameObject::GetWorldMatrix() const
	{
		// no parent - use as-is
		if (Parent == nullptr)
		{
			return GetLocalMatrix();
		}
		// combine w/ parent's world
		else
		{
			return Parent->GetWorldMatrix() * GetLocalMatrix();
		}
	}

	void GameObject::Translate(float x, float y)
	{
		LocalPosition += Vector3(x, y, 0);
	}

	void GameObject::Translate(Vector3 translation)
	{
		LocalPosition += translation;
	}

	void GameObject::Rotate(float radians)
	{
		LocalRotation += radians;
	}

	void GameObject::Scale(float x, float y)
	{
		LocalScale *= Vector3(x, y, 1);
	}

	void GameObject::Scale(Vector3 scaling)
	{
		LocalScale *= scaling;
	}

	void GameObject::Update(float deltaTime)
	{
		OnUpdate(deltaTime);

		for (size_t i = 0; i < Children.size(); ++i)
		{
			Children[i]->Update(deltaTime);
		}
	}

	void GameObject::Draw()
	{
		OnDraw();

		for (size_t i = 0; i < Children.size(); ++i)
		{
			Children[i]->Draw();
		}
	}

	void GameObject::GetLocalTransform(Vector3 & localPos, float & localRot, Vector3 & localScl) const
	{
		// NOTE: Do NOT assign `LocalPosition` directly to `localPos`.
		//       We do not want to provide a reference to our protected variable.
		localPos = Vector3(LocalPosition);
		localRot = float(LocalRotation);
		localScl = Vector3(LocalScale);
	}

	void GameObject::GetWorldTransform(Vector3 & worldPos, float & worldRot, Vector3 & worldScl) const
	{
		const Matrix3 worldTRS = GetWorldMatrix();

		worldPos = Vector3(worldTRS[6], worldTRS[7], worldTRS[8]);
		worldRot = float(AngleFrom2D(worldTRS[0], worldTRS[1]));
		worldScl = Vector3(Vector3(worldTRS.m1, worldTRS.m2, 0).Magnitude(),
						   Vector3(worldTRS.m4, worldTRS.m5, 0).Magnitude(),
						   1.0f);
	}

	Matrix3 GameObject::GetLocalToWorldMatrix() const
	{
		if (Parent == nullptr)
		{
			return Matrix3::MakeIdentity();
		}
		else
		{
			return Parent->GetWorldMatrix();
		}
	}
}